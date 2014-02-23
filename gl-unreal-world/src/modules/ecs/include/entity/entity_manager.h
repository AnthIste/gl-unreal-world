#ifndef INC_ENTITY_ENTITY_MANAGER_H
#define INC_ENTITY_ENTITY_MANAGER_H

#include "entity/entity_subscriber.h"
#include "entity/entity.h"

#include <memory>
#include <set>
#include <map>

namespace ecsentity {

class EntityManager {
public:
    EntityManager();

    virtual ~EntityManager();

    // Makes an entity known to the system
    void registerEntity(std::shared_ptr<ecsentity::Entity> entity);

    // Makes an entity unknown to the system
    void deregisterEntity(std::shared_ptr<ecsentity::Entity> entity);

    // Notifies all subscribers about changes to known entities
    void publishChanges();

    // The subscriber will be notified if an entity is created or destroyed
    // by the EntityManager.
    void subscribeEntityChanges(EntitySubscriber* subscriber);

    // The subscriber will be notified if an entity's component set changes.
    // That is, if a component is added or removed from an entity.
    // The subscriber must provide a set of component types that it is interested
    // in subscribing to.
    void subscribeComponentChanges(EntitySubscriber* subscriber, std::set<unsigned int> componentTypes);

    // The subscriber will no longer be notified of any changes. All references
    // to the subscriber are guaranteed to be removed.
    void unsubscribe(EntitySubscriber* subscriber);

private:
    // Buffer of registered entities
    std::set<std::shared_ptr<ecsentity::Entity> > _entitiesToAdd;

    // Buffer of deregistered entities
    std::set<std::shared_ptr<ecsentity::Entity> > _entitiesToRemove;

    std::map<unsigned int, std::shared_ptr<ecsentity::Entity> > _entities;

    std::set<EntitySubscriber*> _entitySubscribers;

    std::map<unsigned int, std::set<EntitySubscriber*> > _componentSubscribers;
};

};

#endif
