#ifndef INC_SYSTEMS_GAME_LOGIC_H
#define INC_SYSTEMS_GAME_LOGIC_H

#include "system/system.h"

namespace systems {

class GameLogicSystem : public system::System {
public:
    GameLogicSystem(std::shared_ptr<entity::EntityManager> entityManager)
        : system::System(entityManager) { }

    virtual ~GameLogicSystem() { }

    virtual void initialize();

    virtual void entitiesAdded(std::vector<entity::Entity> entities);
};

};

#endif
