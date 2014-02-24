#include "game/game.h"
#include "entity/entity.h"
#include "entity/component.h"

using ecsentity::EntityManager;
using ecsentity::Entity;
using ecsentity::Component;
using ecssystems::GameLogicSystem;
using ecssystems::GfxSystem;

namespace ecsgame {

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
