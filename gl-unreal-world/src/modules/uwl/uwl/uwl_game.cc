#include "uwl_game.h"
#include "uwlec/uwlec_entity.h"
#include "uwlec/uwlec_component.h"

using uwlec::Entity;
using uwlec::Component;
using uwlman::EntityManager;
using uwlsys::GameLogicSystem;
using uwlsys::GfxSystem;
using uwlinf::FileSystem;
using oglwin::WindowManager;
using oglres::AssetManager;

namespace uwl {

const char* WindowTitle = "The Unreal World";
const int WindowWidth = 640;
const int WindowHeight = 640;

Game::Game()
{
    _fileSystem = std::make_shared<FileSystem>();
    _windowManager = std::make_shared<WindowManager>();
    _entityManager = std::make_shared<EntityManager>();
    _assetManager = std::make_shared<AssetManager>(_fileSystem);
    _gameLogicSystem = std::make_shared<GameLogicSystem>(_entityManager);
    _gfxSystem = std::make_shared<GfxSystem>(_entityManager, _assetManager);
}

Game::~Game()
{
}

void Game::initialize()
{
    // Initialize window
    _windowManager->createWindow(WindowTitle, WindowWidth, WindowHeight);

    // Initialize systems
    _gfxSystem->initialize();
    _gameLogicSystem->initialize();

    // Initialize entities
    auto shipEntity = std::make_shared<Entity>();
    _entityManager->registerEntity(shipEntity);
}

void Game::finalize()
{
    _gameLogicSystem->finalize();
    _gfxSystem->finalize();
    _windowManager->closeWindow();
}

bool Game::isDone()
{
    return _windowManager->windowCanClose();
}

void Game::tick()
{
    // Get time delta
    long dt = 0;

    // Process events
    _entityManager->tick(dt);

    // Update game logic
    _gameLogicSystem->tick(dt);

    // Update GFX
    _gfxSystem->tick(dt);

    // Present to window
    _windowManager->redrawWindow();
}

};
