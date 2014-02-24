#ifndef INC_SYSTEM_SYSTEM_H
#define INC_SYSTEM_SYSTEM_H

#include "entity/entity_manager.h"
#include "entity/entity_subscriber.h"

#include <memory>

namespace ecssystem {

class System {
public:
    System(std::shared_ptr<ecsentity::EntityManager> entityManager)
        : _entityManager(entityManager) { }

    virtual ~System();

    virtual void initialize() = 0;

    virtual void finalize() = 0;

protected:
    virtual std::shared_ptr<ecsentity::EntityManager> entityManager() { return _entityManager; }

private:
    std::shared_ptr<ecsentity::EntityManager> _entityManager;
};

};

#endif
