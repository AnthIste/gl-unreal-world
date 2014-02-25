#include "uwl_game.h"
#include "uwlec/uwlec_entity.h"
#include "uwlec/uwlec_component.h"

using uwlec::Entity;
using uwlec::Component;
using uwlman::EntityManager;
using uwlsys::GameLogicSystem;
using uwlsys::GfxSystem;

namespace uwl {

Game::Game()
{
    _entityManager = std::make_shared<EntityManager>();
    _gameLogicSystem = std::make_shared<GameLogicSystem>(_entityManager);
    _gfxSystem = std::make_shared<GfxSystem>(_entityManager);
}

Game::~Game()
{
}

void Game::initialize()
{
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
}

bool Game::isDone()
{
    return _gfxSystem->windowCanClose();
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
}

};
