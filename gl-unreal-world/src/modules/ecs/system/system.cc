#include "system/system.h"
#include "entity/entity_manager.h"

namespace system {

using entity::EntityManager;

System::~System()
{
}

void System::entitiesAdded(std::vector<entity::Entity> entities)
{
}

};
