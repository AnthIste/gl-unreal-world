#ifndef INC_ENTITY_ENTITY_MANAGER_H
#define INC_ENTITY_ENTITY_MANAGER_H

#include "entity/entity_subscriber.h"
#include "entity/entity.h"
#include "entity/component.h"

#include <memory>
#include <set>
#include <map>

namespace ecsentity {

class EntityManager {
public:
    EntityManager();

    virtual ~EntityManager();

    // Makes an entity known to the system
    void registerEntity(std::shared_ptr<Entity> entity);

    // Makes an entity unknown to the system
    void deregisterEntity(std::shared_ptr<Entity> entity);

    // Associate a component with an entity and make the component known to the system
    void addComponent(std::shared_ptr<Entity> entity, std::shared_ptr<Component> component);

    // Unassociate a component with an entity and make the component unknown to the system
    void removeComponent(std::shared_ptr<Entity> entity, unsigned int componentId);

    // Notifies all subscribers about changes to known entities
    void publishChanges();

    // The subscriber will be notified if an entity is registered or
    // unregistered with the EntityManager
    void subscribeEntityChanges(EntitySubscriber* subscriber);

    // The subscriber will be notified if an entity's component set changes.
    // That is, if a component is added or removed from an entity.
    // The subscriber must provide a set of component types that it is interested
    // in subscribing to.
    void subscribeComponentChanges(EntitySubscriber* subscriber, std::set<component_t> componentTypes);

    // The subscriber will no longer be notified of any changes. All references
    // to the subscriber are guaranteed to be removed.
    void unsubscribe(EntitySubscriber* subscriber);

private:
    // Assumes a single-threaded environment. Returns monotonically
    // increasing identifiers.
    unsigned int newIdentity();

private:
    // Buffer of registered entities
    std::set<std::shared_ptr<Entity> > _entitiesToAdd;

    // Buffer of deregistered entities
    std::set<std::shared_ptr<Entity> > _entitiesToRemove;

    // All entities, indexed by ID
    std::map<unsigned int, std::shared_ptr<Entity> > _entitiesById;

    // All components, indexed by id
    std::map<unsigned int, std::shared_ptr<Component> > _componentsById;

    // All components, indexed by type
    std::map<component_t, std::shared_ptr<Component> > _componentsByType;

    // Subscribers to entity add/remove events
    std::set<EntitySubscriber*> _entitySubscribers;

    // Subscribers to component add/remove events
    std::map<component_t, std::set<EntitySubscriber*> > _componentSubscribers;

    // Misc
    unsigned int _identitySeed;
};

};

#endif
