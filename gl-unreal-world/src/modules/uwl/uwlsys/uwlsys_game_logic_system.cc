#include "uwlsys_game_logic_system.h"
#include "uwlec/uwlec_moveable.h"
#include "uwlevt/commands.h"

#include <log4cxx/logger.h>
#include <cmath>

using namespace log4cxx;

using uwlec::Entity;
using uwlec::Moveable;
using uwlman::EntityManager;
using uwlman::EntityType;
using uwlsys::KeyMap;

namespace uwlsys {

const double Gravity = -0.115;
const double Bounciness = 0.7;
const double ThrowStrength = 0.04;
const double JitterThreshold = 0.013;

void GameLogicSystem::initialize()
{
    LOG4CXX_DEBUG(Logger::getRootLogger(), "uwlsys::GameLogicSystem - "
        << "Initializing random number generator");

    _random.seed(std::mt19937_64::default_seed);

    LOG4CXX_DEBUG(Logger::getRootLogger(), "uwlsys::GameLogicSystem - "
        << "Creating Player Character entity");

    _pc = _entityFactory->createEntity(EntityType::Wooter, 0.0, 0.0);

    subscribeEvents();
}

void GameLogicSystem::finalize()
{
}

void GameLogicSystem::tick(double t, double dt)
{
    EntityManager::EntitySet allEntities = entityManager()->allEntities();

    for (auto entity : allEntities) {
        moveEntity(dt, entity);
        applyGravity(dt, entity);
        detectCollisions(dt, entity);
    }

    movePC();
}

void GameLogicSystem::receiveMessage(std::shared_ptr<uwlinf::Message> message)
{
    LOG4CXX_DEBUG(Logger::getRootLogger(), "uwlsys::GameLogicSystem - "
        << "Event received: "
        << typeid(*message).name());

    if (message->is<uwlevt::CommandThrow>()) {
        throwPC();
        spawnGuzzler();
    }
}

void GameLogicSystem::subscribeEvents()
{
    LOG4CXX_DEBUG(Logger::getRootLogger(), "uwlsys::GameLogicSystem - "
        << "Subscribing to events");

    auto thisReceiver = shared_from_this();

    _eventManager->registerReceiver<uwlevt::CommandThrow>(thisReceiver);
}

void GameLogicSystem::moveEntity(double dt, std::shared_ptr<uwlec::Entity> entity)
{
    auto m = entityManager()->getComponent<Moveable>(entity);

    if (m != nullptr) {
        m->x += m->dx;
        m->y += m->dy;
        m->z += m->dz;
    }
}

void GameLogicSystem::applyGravity(double dt, std::shared_ptr<uwlec::Entity> entity)
{
    auto m = entityManager()->getComponent<Moveable>(entity);

    if (m != nullptr) {
        m->dy += Gravity * dt;
    }
}

void GameLogicSystem::detectCollisions(double dt, std::shared_ptr<uwlec::Entity> entity)
{
    auto m = entityManager()->getComponent<Moveable>(entity);

    if (m->y < -1.0) {
        m->y = -1.0;

        if (std::abs(m->dy) > JitterThreshold) {
            m->dy = -(m->dy) * Bounciness;
        }
        else {
            m->dy = 0;
        }
    }
}

void GameLogicSystem::movePC()
{
    if (_inputSystem->isKeyDown(KeyMap::Throw)) {
        auto dy = entityManager()->getComponent<Moveable>(_pc)->dy += 0.0025;
    }
    /*
    if (_inputSystem->isKeyDown(KeyMap::MoveForward)) {
        entityManager()->getComponent<Moveable>(_pc)->dy = 0.0001;
    }
    else if (_inputSystem->isKeyDown(KeyMap::MoveBackward)) {
        entityManager()->getComponent<Moveable>(_pc)->dy = -0.0001;
    }
    else {
        entityManager()->getComponent<Moveable>(_pc)->dy = 0.0;
    }
    */

    if (_inputSystem->isKeyDown(KeyMap::MoveLeft)) {
        entityManager()->getComponent<Moveable>(_pc)->dx -= 0.001;
    }
    else if (_inputSystem->isKeyDown(KeyMap::MoveRight)) {
        entityManager()->getComponent<Moveable>(_pc)->dx += 0.001;
    }
    else {
        entityManager()->getComponent<Moveable>(_pc)->dx /= 1.1;
    }
}

void GameLogicSystem::throwPC()
{
    entityManager()->getComponent<Moveable>(_pc)->dy += ThrowStrength;
}

void GameLogicSystem::spawnGuzzler()
{
    // x in [-1.0, 1.0]
    auto x = (_random() % 2000) / 1000.0 - 1.0;

    // dy in [0, 0.008]
    auto dy = (_random() % 8000) / 100000.0;

    auto guzzler = _entityFactory->createEntity(EntityType::Guzzler, x, 0.0);
    entityManager()->getComponent<Moveable>(guzzler)->dy = dy;
}

};
