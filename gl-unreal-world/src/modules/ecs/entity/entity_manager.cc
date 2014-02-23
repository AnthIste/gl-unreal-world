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
    _identitySeed = 1;
}

EntityManager::~EntityManager()
{
}

void EntityManager::registerEntity(shared_ptr<Entity> entity) {
    entity->id = newIdentity();

    _entitiesToAdd.insert(entity);
    _entitiesToRemove.erase(entity);
}

void EntityManager::deregisterEntity(shared_ptr<Entity> entity) {
    _entitiesToRemove.insert(entity);
    _entitiesToAdd.erase(entity);
}

void EntityManager::addComponent(std::shared_ptr<Entity> entity, shared_ptr<Component> component) {
    component->id = newIdentity();

    entity->components.insert(component->id);
}

void EntityManager::removeComponent(std::shared_ptr<Entity> entity, unsigned int componentId) {
}

void EntityManager::publishChanges() {
    if (_entitiesToAdd.size() == 0 && _entitiesToRemove.size() == 0) {
        return;
    }

    for (auto entity : _entitiesToAdd) {
        _entitiesById[entity->id] = entity;
    }

    // Publish to subscribers
    std::cout << _entitiesToAdd.size() << " entities added" << std::endl;

    for (auto entity : _entitiesToRemove) {
        _entitiesById.erase(entity->id);
    }

    // Publish to subscribers

    _entitiesToAdd.clear();
    _entitiesToRemove.clear();
}

void EntityManager::subscribeEntityChanges(EntitySubscriber* subscriber)
{
    _entitySubscribers.insert(subscriber);
}

void EntityManager::subscribeComponentChanges(EntitySubscriber* subscriber, set<component_t> componentTypes)
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

unsigned int EntityManager::newIdentity()
{
    return _identitySeed++;
}

};
