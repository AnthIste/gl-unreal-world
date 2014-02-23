#include "system/system.h"
#include "entity/entity_manager.h"

namespace system {

using entity::EntityManager;

System::~System()
{
}

void System::initialize()
{
    entityManager()->subscribeEntityChanges(this);
}

void System::finalize()
{
    entityManager()->unsubscribe(this);
}

void System::entitiesAdded(std::vector<entity::Entity> entities)
{
}

};
