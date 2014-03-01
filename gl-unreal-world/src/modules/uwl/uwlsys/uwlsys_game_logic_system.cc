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
}

void GameLogicSystem::finalize()
{
}

void GameLogicSystem::tick(double t, double dt)
{
    EntityManager::EntitySet allEntities = _entityManager->allEntities();
    std::shared_ptr<Entity> toRemove;

    for (auto entity : allEntities) {
        auto m = _entityManager->getComponent<Moveable>(entity);

        if (m != nullptr) {
            auto y = sin(t * m->dy);
            m->y = y;
        }

        toRemove = entity;
    }

    if (t > 5.0 && allEntities.size() == 2) {
        _entityFactory->createEntity(EntityType::Wooter, 0.0, 0.0);
    }
}

};
