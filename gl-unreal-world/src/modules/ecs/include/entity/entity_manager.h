#ifndef INC_ENTITY_ENTITY_MANAGER_H
#define INC_ENTITY_ENTITY_MANAGER_H

#include "entity/entity_subscriber.h"

#include <set>
#include <map>

namespace entity {

class EntityManager {
public:
    EntityManager();

    virtual ~EntityManager();

    // The subscriber will be notified if an entity is created or destroyed
    // by the EntityManager.
    void subscribeEntityChanges(EntitySubscriber* subscriber);

    // The subscriber will be notified if an entity's component set changes.
    // That is, if a component is added or removed from an entity.
    // The subscriber must provide a set of component types that it is interested
    // in subscribing to.
    void subscribeComponentChanges(EntitySubscriber* subscriber, std::set<unsigned int> componentTypes);

private:
    std::set<EntitySubscriber*> _entitySubscribers;

    std::map<unsigned int, std::set<EntitySubscriber*> > _componentSubscribers;
};

};

#endif
