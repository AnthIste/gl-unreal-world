#include "systems/game_logic.h"

namespace ecssystems {

using std::shared_ptr;
using ecsentity::EntitySubscriber;

void GameLogicSystem::initialize()
{
}

void GameLogicSystem::entitiesAdded(std::vector<ecsentity::Entity> entities)
{
    // Filter by component types and add to local storage
}

};
