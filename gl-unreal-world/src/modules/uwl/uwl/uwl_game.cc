#include "uwl_game.h"
#include "uwlec/uwlec_entity.h"
#include "uwlec/uwlec_component.h"
#include "uwlec/uwlec_moveable.h"
#include "uwlevt/commands.h"

#include <thread>

namespace uwl {

const char* WindowTitle = "The Unreal World";
const int WindowWidth = 640;
const int WindowHeight = 640;

// Simulation timestep
const double fps = 60.0;
const double dt = 1.0 / fps;
const long FakeRenderTimeMillis = 0;

Game::Game()
{
    // Infrastructure
    _clock = std::make_shared<uwlinf::Clock>();
    _timeStep = std::make_shared<uwlinf::TimeStep>(_clock, dt);
    _fileSystem = std::make_shared<uwlinf::FileSystem>();
    _messageQueue = std::make_shared<uwlinf::MessageQueue>();

    // OpenGL
    _assetManager = std::make_shared<oglres::AssetManager>(_fileSystem);
    _windowManager = std::make_shared<oglwin::WindowManager>();
    _inputManager = std::make_shared<oglwin::InputManager>(_windowManager);

    // Managers
    _entityManager = std::make_shared<uwlman::EntityManager>();
    _entityFactory = std::make_shared<uwlman::EntityFactory>(_entityManager);
    _eventManager = std::make_shared<uwlman::EventManager>(_messageQueue);

    // Systems
    _inputSystem = std::make_shared<uwlsys::InputSystem>(_entityManager, _inputManager, _messageQueue);
    _gameLogicSystem = std::make_shared<uwlsys::GameLogicSystem>(_entityManager, _entityFactory, _eventManager, _inputSystem);
    _gfxSystem = std::make_shared<uwlsys::GfxSystem>(_entityManager, _assetManager);
}

Game::~Game()
{
}

void Game::initialize()
{
    // Initialize OpenGL
    _windowManager->createWindow(WindowTitle, WindowWidth, WindowHeight);
    _inputManager->initialize();

    // Initialize systems
    _inputSystem->initialize();
    _gfxSystem->initialize();
    _gameLogicSystem->initialize();

    // Subscribe to events
    subscribeEvents();
}

void Game::finalize()
{
    // Finalize systems
    _gameLogicSystem->finalize();
    _gfxSystem->finalize();
    _inputSystem->finalize();

    // Finalize OpenGL
    _inputManager->finalize();
    _windowManager->closeWindow();
}

bool Game::isDone()
{
    return _windowManager->windowCanClose();
}

void Game::tick()
{
    // Proceed time
    _timeStep->tick();

    // Handle events
    _eventManager->dispatchMessages();
    _entityManager->processChanges();

    // Process input
    _inputSystem->tick(_timeStep->rt(), _timeStep->rdt());

    // Update simulation
    while (_timeStep->hasTime()) {
        _gameLogicSystem->tick(_timeStep->t(), _timeStep->dt());
        _timeStep->consumeTime();
    }

    // Optional: use time alpha value interpolation

    // Render
    _gfxSystem->tick(_timeStep->rt(), _timeStep->rdt());
    _windowManager->redrawWindow();

    // Simulate slow rendering of frames for FPS and timestep testing
    if (FakeRenderTimeMillis > 0) {
        std::chrono::milliseconds extraTime(FakeRenderTimeMillis);
        std::this_thread::sleep_for(extraTime);
    }
}

void Game::receiveMessage(std::shared_ptr<uwlinf::Message> message)
{
    if (message->is<uwlevt::CommandExit>()) {
        _windowManager->closeWindow();
    }
}

void Game::subscribeEvents()
{
    auto thisReceiver = shared_from_this();

    _eventManager->registerReceiver<uwlevt::CommandExit>(thisReceiver);
}

};
