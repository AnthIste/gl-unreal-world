#include "entity/entity_manager.h"

#include <algorithm>
#include <iostream>

using std::set;
using std::map;

namespace entity {

EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
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
