#include "system/system.h"
#include "entity/entity_manager.h"

namespace ecssystem {

using ecsentity::EntityManager;

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

void System::entitiesAdded(std::vector<ecsentity::Entity> entities)
{
}

};
