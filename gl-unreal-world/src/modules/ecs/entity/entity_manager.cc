#include "entity/entity_manager.h"
#include "entity/entity.h"

#include <algorithm>
#include <iostream>
#include <vector>

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

void EntityManager::registerEntity(shared_ptr<Entity> entity)
{
    entity->id = newIdentity();
    _entitiesById[entity->id] = entity;
}

void EntityManager::deregisterEntity(shared_ptr<Entity> entity)
{
    _entitiesById.erase(entity->id);
}

template <typename TComponent>
void EntityManager::addComponent(shared_ptr<Entity> entity, shared_ptr<TComponent> component)
{
    auto key = typeid(TComponent).hash_code();

    component->id = newIdentity();
    entity->components[key] = component->id;
}

template <typename TComponent>
void EntityManager::removeComponent(shared_ptr<Entity> entity)
{
    auto key = typeid(TComponent).hash_code();

    entity->components.erase(key);
}

template <typename TComponent>
shared_ptr<TComponent> EntityManager::getComponent(shared_ptr<Entity> entity) const
{
    return nullptr;
}

set<shared_ptr<Entity>> EntityManager::allEntities() const
{
    // TODO: move to utility library
    // Also, this should probably be cached...
    std::set<shared_ptr<Entity>> values;

    std::transform(
        _entitiesById.begin(),
        _entitiesById.end(),
        std::inserter(values, values.begin()),
        [](EntityMap::value_type val) { return val.second; } );

    return values;
}

unsigned int EntityManager::newIdentity()
{
    return _identitySeed++;
}

};
