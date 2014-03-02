#ifndef INC_UWLSYS_GAME_LOGIC_SYSTEM_H
#define INC_UWLSYS_GAME_LOGIC_SYSTEM_H

#include "uwlsys_system.h"
#include "uwlman/uwlman_entity_manager.h"
#include "uwlman/uwlman_entity_factory.h"
#include "uwlman/uwlman_event_manager.h"
#include "uwlman/uwlman_message_receiver.h"
#include "uwlsys/uwlsys_input_system.h"

#include <random>

namespace uwlsys {

class GameLogicSystem : public uwlsys::System,
                        public uwlman::MessageReceiver {
public:
    GameLogicSystem(
        std::shared_ptr<uwlman::EntityManager> entityManager,
        std::shared_ptr<uwlman::EntityFactory> entityFactory,
        std::shared_ptr<uwlman::EventManager> eventManager,
        std::shared_ptr<uwlsys::InputSystem> inputSystem)
    :
        uwlsys::System(entityManager),
        uwlman::MessageReceiver(),
        _entityFactory(entityFactory),
        _eventManager(eventManager),
        _inputSystem(inputSystem)
    { }

    virtual ~GameLogicSystem() { }

    virtual void initialize();

    virtual void finalize();

    virtual void tick(double t, double dt);

    virtual void receiveMessage(std::shared_ptr<uwlinf::Message> message);

private:
    void subscribeEvents();

    void moveEntity(double dt, std::shared_ptr<uwlec::Entity> entity);

    void applyGravity(double dt, std::shared_ptr<uwlec::Entity> entity);

    void detectCollisions(double dt, std::shared_ptr<uwlec::Entity> entity);

    void movePC();

    void throwPC();

    void spawnGuzzler();

private:
    std::shared_ptr<uwlman::EntityFactory> _entityFactory;

    std::shared_ptr<uwlman::EventManager> _eventManager;

    std::shared_ptr<uwlsys::InputSystem> _inputSystem;

    std::shared_ptr<uwlec::Entity> _pc;

    std::mt19937_64 _random;
};

};

#endif
