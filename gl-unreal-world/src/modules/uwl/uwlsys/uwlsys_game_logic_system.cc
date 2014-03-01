#include "uwlsys_game_logic_system.h"
#include "uwlec/uwlec_moveable.h"

#include <cmath>

using uwlec::Entity;
using uwlec::Moveable;
using uwlman::EntityManager;
using uwlman::EntityType;

namespace uwlsys {

void GameLogicSystem::initialize()
{
    // Create Player Character (PC)
    _pc = _entityFactory->createEntity(EntityType::Wooter, 0.0, 0.0);
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

};
