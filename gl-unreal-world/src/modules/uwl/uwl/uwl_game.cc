#include "uwl_game.h"
#include "uwlec/uwlec_entity.h"
#include "uwlec/uwlec_component.h"
#include "uwlec/uwlec_moveable.h"
#include "uwlevt/commands.h"

using uwlec::Entity;
using uwlec::Moveable;

namespace uwl {

const char* WindowTitle = "The Unreal World";
const int WindowWidth = 640;
const int WindowHeight = 640;

static void createEntity(std::shared_ptr<uwlman::EntityManager> _entityManager, double x);

Game::Game()
{
    // Infrastructure
    _clock = std::make_shared<uwlinf::Clock>();
    _fileSystem = std::make_shared<uwlinf::FileSystem>();
    _messageQueue = std::make_shared<uwlinf::MessageQueue>();

    // OpenGL
    _assetManager = std::make_shared<oglres::AssetManager>(_fileSystem);
    _windowManager = std::make_shared<oglwin::WindowManager>();
    _inputManager = std::make_shared<oglwin::InputManager>(_windowManager, _messageQueue);

    // Managers
    _entityManager = std::make_shared<uwlman::EntityManager>();
    _eventManager = std::make_shared<uwlman::EventManager>(_messageQueue);

    // Systems
    _gameLogicSystem = std::make_shared<uwlsys::GameLogicSystem>(_entityManager);
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
    _gfxSystem->initialize();
    _gameLogicSystem->initialize();

    // Initialize entities
    createEntity(_entityManager, -0.5);
    createEntity(_entityManager, 0.5);

    // Subscribe to events
    subscribeEvents();
}

void Game::finalize()
{
    // Finalize systems
    _gameLogicSystem->finalize();

    // Finalize OpenGL
    _inputManager->finalize();
    _gfxSystem->finalize();

    // Finalize window
    _windowManager->closeWindow();
}

bool Game::isDone()
{
    return _windowManager->windowCanClose();
}

void Game::tick()
{
    // Proceed time
    auto dt = _clock->tick();
    auto t = _clock->getTime();

    // Handle events
    _eventManager->dispatchMessages();

    // Process input
    _inputManager->processInput();

    // Process entity events
    _entityManager->processChanges();

    // Update game logic
    _gameLogicSystem->tick(t, dt);

    // Update GFX
    _gfxSystem->tick(t, dt);

    // Present to window
    _windowManager->redrawWindow();
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

static void createEntity(std::shared_ptr<uwlman::EntityManager> _entityManager, double x)
{
    auto shipEntity = std::make_shared<Entity>();
    auto moveableComponent = std::make_shared<Moveable>();

    moveableComponent->x = x;

    _entityManager->registerEntity(shipEntity);
    _entityManager->addComponent<Moveable>(shipEntity, moveableComponent);
}

};
