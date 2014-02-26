#ifndef INC_SYSTEM_SYSTEM_H
#define INC_SYSTEM_SYSTEM_H

#include "uwlman/uwlman_entity_manager.h"

#include <memory>

namespace uwlsys {

class System {
public:
    System(std::shared_ptr<uwlman::EntityManager> entityManager)
        : _entityManager(entityManager) { }

    virtual ~System();

    virtual void initialize() = 0;

    virtual void finalize() = 0;

    virtual void tick(double t, double dt) = 0;

protected:
    virtual std::shared_ptr<uwlman::EntityManager> entityManager() { return _entityManager; }

private:
    std::shared_ptr<uwlman::EntityManager> _entityManager;
};

};

#endif
