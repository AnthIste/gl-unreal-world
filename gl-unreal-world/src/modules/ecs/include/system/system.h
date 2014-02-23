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

    virtual void entitiesAdded(std::vector<entity::Entity> entities);

private:
    std::shared_ptr<entity::EntityManager> _entityManager;
};

};

#endif
