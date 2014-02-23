#include "entity/entity_manager.h"

namespace entity {

EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
}

void EntityManager::subscribeEntityChanges(std::shared_ptr<EntitySubscriber> subscriber)
{
}

void EntityManager::subscribeComponentChanges(std::shared_ptr<EntitySubscriber> subscriber, std::vector<unsigned int> componentTypes)
{
}

};
