#include "systems/game_logic.h"

namespace systems {

using std::shared_ptr;
using entity::EntitySubscriber;

void GameLogicSystem::initialize()
{
}

void GameLogicSystem::entitiesAdded(std::vector<entity::Entity> entities)
{
    // Filter by component types and add to local storage
}

};
