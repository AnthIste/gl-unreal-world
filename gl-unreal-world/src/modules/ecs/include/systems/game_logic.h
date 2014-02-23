#ifndef INC_SYSTEMS_GAME_LOGIC_H
#define INC_SYSTEMS_GAME_LOGIC_H

#include "system/system.h"

namespace ecssystems {

class GameLogicSystem : public ecssystem::System {
public:
    GameLogicSystem(std::shared_ptr<ecsentity::EntityManager> entityManager)
        : ecssystem::System(entityManager) { }

    virtual ~GameLogicSystem() { }

    virtual void initialize();

    virtual void entitiesAdded(std::vector<ecsentity::Entity> entities);
};

};

#endif
