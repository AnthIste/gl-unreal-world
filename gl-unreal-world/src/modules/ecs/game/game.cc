#include "game/game.h"
#include "entity/entity.h"
#include "entity/component.h"

using ecsentity::EntityManager;
using ecsentity::Entity;
using ecsentity::Component;
using ecssystems::GameLogicSystem;

namespace ecsgame {

Game::Game()
{
    _entityManager = std::make_shared<EntityManager>();
    _gameLogicSystem = std::make_shared<GameLogicSystem>(_entityManager);
}

Game::~Game()
{
}

void Game::initialize()
{
    // Initialize systems
    _gameLogicSystem->initialize();

    // Initialize entities
    auto shipEntity = std::make_shared<Entity>();
    _entityManager->registerEntity(shipEntity);
}

void Game::finalize()
{
    _gameLogicSystem->finalize();
}

void Game::tick()
{
    // Get time delta
    // Update game logic
    // Update GFX
}

};
