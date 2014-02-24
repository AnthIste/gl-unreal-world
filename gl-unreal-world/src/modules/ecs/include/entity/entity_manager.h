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
    typedef std::set<std::shared_ptr<Entity>> EntitySet;

public:
    EntityManager();

    virtual ~EntityManager();

    /// <summary>
    /// Makes an entity known to the system
    /// </summary>
    void registerEntity(std::shared_ptr<Entity> entity);

    /// <summary>
    /// Makes an entity unknown to the system
    /// </summary>
    void deregisterEntity(std::shared_ptr<Entity> entity);

    /// <summary>
    /// Associate a component with an entity and make the component known to the system
    /// </summary>
    template <typename TComponent>
    void addComponent(std::shared_ptr<Entity> entity, std::shared_ptr<TComponent> component);

    /// <summary>
    /// Unassociate a component with an entity and make the component unknown to the system
    /// </summary>
    template <typename TComponent>
    void removeComponent(std::shared_ptr<Entity> entity);

    /// <summary>
    /// Unassociate a component with an entity and make the component unknown to the system
    /// </summary>
    template <typename TComponent>
    std::shared_ptr<TComponent> getComponent(std::shared_ptr<Entity> entity) const;

    /// <summary>
    /// Returns a collection of all known entities
    /// </summary>
    EntitySet allEntities() const;

    /// <summary>
    /// Do time-related work
    /// </summary>
    void tick(long t);

private:
    // Assumes a single-threaded environment. Returns monotonically
    // increasing identifiers.
    unsigned int newIdentity();

private:
    typedef std::map<unsigned int, std::shared_ptr<Entity>> EntityMap;
    typedef std::map<unsigned int, std::shared_ptr<Component>> ComponentMap;

    // All entities, indexed by ID
    EntityMap _entitiesById;

    // All components, indexed by id
    ComponentMap _componentsById;

    // Misc
    unsigned int _identitySeed;

    // These buffers should probably be replaced by a Command
    // on the message bus
    EntityMap _entitiesAdded;
    EntityMap _entitiesDestroyed;
};

};

#endif
