#ifndef INC_UWLSYS_GAME_LOGIC_SYSTEM_H
#define INC_UWLSYS_GAME_LOGIC_SYSTEM_H

#include "uwlsys_system.h"
#include "uwlman/uwlman_entity_manager.h"
#include "uwlman/uwlman_entity_factory.h"
#include "uwlsys/uwlsys_input_system.h"

namespace uwlsys {

class GameLogicSystem : public uwlsys::System {
public:
    GameLogicSystem(
        std::shared_ptr<uwlman::EntityManager> entityManager,
        std::shared_ptr<uwlman::EntityFactory> entityFactory,
        std::shared_ptr<uwlsys::InputSystem> inputSystem)
    :
        uwlsys::System(entityManager),
        _entityFactory(entityFactory),
        _inputSystem(inputSystem)
    { }

    virtual ~GameLogicSystem() { }

    virtual void initialize();

    virtual void finalize();

    virtual void tick(double t, double dt);

private:
    void moveEntity(std::shared_ptr<uwlec::Entity> entity);

    void applyGravity(std::shared_ptr<uwlec::Entity> entity);

    void detectCollisions(std::shared_ptr<uwlec::Entity> entity);

    void movePC();

private:
    std::shared_ptr<uwlman::EntityFactory> _entityFactory;

    std::shared_ptr<uwlsys::InputSystem> _inputSystem;

    std::shared_ptr<uwlec::Entity> _pc;

};

};

#endif
