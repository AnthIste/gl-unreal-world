#include "entity/entity_manager.h"
#include "entity/entity.h"

#include <algorithm>
#include <iostream>

using std::shared_ptr;
using std::set;
using std::map;

using ecsentity::Entity;

namespace ecsentity {

EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
}

void EntityManager::registerEntity(shared_ptr<Entity> entity) {
    _entitiesToAdd.insert(entity);
    _entitiesToRemove.erase(entity);
}

void EntityManager::deregisterEntity(shared_ptr<Entity> entity) {
    _entitiesToRemove.insert(entity);
    _entitiesToAdd.erase(entity);
}

void EntityManager::publishChanges() {
    for (auto entity : _entitiesToAdd) {
        _entities[entity->id] = entity;
    }

    // Publish to subscribers

    for (auto entity : _entitiesToRemove) {
        _entities.erase(entity->id);
    }

    // Publish to subscribers

    _entitiesToAdd.clear();
    _entitiesToRemove.clear();
}

void EntityManager::subscribeEntityChanges(EntitySubscriber* subscriber)
{
    _entitySubscribers.insert(subscriber);
}

void EntityManager::subscribeComponentChanges(EntitySubscriber* subscriber, set<unsigned int> componentTypes)
{
    for (auto componentType : componentTypes) {
        auto subscriberList = _componentSubscribers[componentType];

        subscriberList.insert(subscriber);
    }
}

void EntityManager::unsubscribe(EntitySubscriber* subscriber)
{
    _entitySubscribers.erase(subscriber);

    for (auto kvp : _componentSubscribers) {
        auto subscriberList = kvp.second;
        subscriberList.erase(subscriber);
    }
}

};
