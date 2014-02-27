#include "uwl_game.h"
#include "uwlec/uwlec_entity.h"
#include "uwlec/uwlec_component.h"
#include "uwlec/uwlec_moveable.h"

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

    // OpenGL
    _assetManager = std::make_shared<oglres::AssetManager>(_fileSystem);
    _windowManager = std::make_shared<oglwin::WindowManager>();
    _inputManager = std::make_shared<oglwin::InputManager>(_windowManager);

    // Managers
    _entityManager = std::make_shared<uwlman::EntityManager>();

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

    // Process input
    // Escape closes
    if (_inputManager->isKeyDown(256)) {
        _windowManager->closeWindow();
    }

    // T engages slow-mo
    if (_inputManager->isKeyDown(84)) {
        _clock->setTimeScale(2.0);
    }

    // Y engages normal time
    if (_inputManager->isKeyDown(89)) {
        _clock->setTimeScale(1.0);
    }

    // Process entity events
    _entityManager->processChanges();

    // Update game logic
    _gameLogicSystem->tick(t, dt);

    // Update GFX
    _gfxSystem->tick(t, dt);

    // Present to window
    _windowManager->redrawWindow();
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
