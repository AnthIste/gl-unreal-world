#ifndef INC_SYSTEM_SYSTEM_H
#define INC_SYSTEM_SYSTEM_H

#include "entity/entity_manager.h"
#include "entity/entity_subscriber.h"

#include <memory>

namespace system {

class System : public entity::EntitySubscriber {
public:
    System(std::shared_ptr<entity::EntityManager> entityManager)
        : _entityManager(entityManager) { }

    virtual ~System();

    virtual void initialize();

    virtual void finalize();

    virtual void entitiesAdded(std::vector<entity::Entity> entities);

protected:
    virtual std::shared_ptr<entity::EntityManager> entityManager() { return _entityManager; }

private:
    std::shared_ptr<entity::EntityManager> _entityManager;
};

};

#endif
