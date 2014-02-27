#ifndef INC_UWLSYS_GAME_LOGIC_SYSTEM_H
#define INC_UWLSYS_GAME_LOGIC_SYSTEM_H

#include "uwlsys_system.h"
#include "uwlman/uwlman_entity_manager.h"

namespace uwlsys {

class GameLogicSystem : public uwlsys::System {
public:
    GameLogicSystem(std::shared_ptr<uwlman::EntityManager> entityManager)
        : uwlsys::System(entityManager),
         _entityManager(entityManager)
    { }

    virtual ~GameLogicSystem() { }

    virtual void initialize();

    virtual void finalize();

    virtual void tick(double t, double dt);

private:
    std::shared_ptr<uwlman::EntityManager> _entityManager;

};

};

#endif
