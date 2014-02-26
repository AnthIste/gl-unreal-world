#include "uwlman_entity_manager.h"
#include "uwlec/uwlec_entity.h"

#include <algorithm>
#include <iostream>
#include <vector>

using std::shared_ptr;
using std::set;
using std::map;

using uwlec::Entity;

namespace uwlman {

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
    _entitiesAdded[entity->id] = entity;
}

void EntityManager::deregisterEntity(shared_ptr<Entity> entity)
{
    _entitiesDestroyed[entity->id] = entity;
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

void EntityManager::processChanges()
{
    // Add new entities
    for (auto kvp : _entitiesAdded) {
        auto id = kvp.first;
        auto entity = kvp.second;

        _entitiesById[entity->id] = entity;
    }

    // Remove deleted entities
    for (auto kvp : _entitiesDestroyed) {
        auto id = kvp.first;
        auto entity = kvp.second;

        _entitiesById.erase(entity->id);
    }
}

unsigned int EntityManager::newIdentity()
{
    return _identitySeed++;
}

};
