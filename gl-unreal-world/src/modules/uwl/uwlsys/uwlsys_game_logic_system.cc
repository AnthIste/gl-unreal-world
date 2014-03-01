#include "uwlsys_game_logic_system.h"
#include "uwlec/uwlec_moveable.h"
#include "uwlevt/commands.h"

#include <cmath>

using uwlec::Entity;
using uwlec::Moveable;
using uwlman::EntityManager;
using uwlman::EntityType;
using uwlsys::KeyMap;

namespace uwlsys {

const double Gravity = -0.000000035;
const double Bounciness = 0.7;

void GameLogicSystem::initialize()
{
    // Create Player Character (PC)
    _pc = _entityFactory->createEntity(EntityType::Wooter, 0.0, 0.0);

    // Subscribe to events
    subscribeEvents();
}

void GameLogicSystem::finalize()
{
}

void GameLogicSystem::tick(double t, double dt)
{
    EntityManager::EntitySet allEntities = entityManager()->allEntities();

    for (auto entity : allEntities) {
        moveEntity(entity);
    }

    applyGravity(_pc);
    detectCollisions(_pc);
}

void GameLogicSystem::receiveMessage(std::shared_ptr<uwlinf::Message> message)
{
    if (message->is<uwlevt::CommandThrow>()) {
        throwPC();
    }
}

void GameLogicSystem::subscribeEvents()
{
    auto thisReceiver = shared_from_this();

    _eventManager->registerReceiver<uwlevt::CommandThrow>(thisReceiver);
}

void GameLogicSystem::moveEntity(std::shared_ptr<uwlec::Entity> entity)
{
    auto m = entityManager()->getComponent<Moveable>(entity);

    if (m != nullptr) {
        m->x += m->dx;
        m->y += m->dy;
        m->z += m->dz;
    }
}

void GameLogicSystem::applyGravity(std::shared_ptr<uwlec::Entity> entity)
{
    auto m = entityManager()->getComponent<Moveable>(entity);

    if (m != nullptr) {
        m->dy += Gravity;
    }
}

void GameLogicSystem::detectCollisions(std::shared_ptr<uwlec::Entity> entity)
{
    auto m = entityManager()->getComponent<Moveable>(entity);

    if (m->y < -1.0) {
        m->y = -1.0;

        if (std::abs(m->dy) > 2.92426e-05) {
            m->dy = -(m->dy) * Bounciness;
        }
        else {
            m->dy = 0;
        }
    }
}

void GameLogicSystem::movePC()
{
    if (_inputSystem->isKeyDown(KeyMap::MoveForward)) {
        entityManager()->getComponent<Moveable>(_pc)->dy = 0.0001;
    }
    else if (_inputSystem->isKeyDown(KeyMap::MoveBackward)) {
        entityManager()->getComponent<Moveable>(_pc)->dy = -0.0001;
    }
    else {
        entityManager()->getComponent<Moveable>(_pc)->dy = 0.0;
    }

    if (_inputSystem->isKeyDown(KeyMap::MoveLeft)) {
        entityManager()->getComponent<Moveable>(_pc)->dx = -0.0001;
    }
    else if (_inputSystem->isKeyDown(KeyMap::MoveRight)) {
        entityManager()->getComponent<Moveable>(_pc)->dx = 0.0001;
    }
    else {
        entityManager()->getComponent<Moveable>(_pc)->dx = 0.0;
    }
}

void GameLogicSystem::throwPC()
{
    entityManager()->getComponent<Moveable>(_pc)->dy += 0.0002;
}

};
