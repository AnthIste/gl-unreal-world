#include "uwlsys_game_logic_system.h"
#include "uwlec/uwlec_moveable.h"

#include <cmath>

using uwlec::Entity;
using uwlec::Moveable;
using uwlman::EntityManager;

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

    for (auto entity : allEntities) {
        auto m = _entityManager->getComponent<Moveable>(entity);

        if (m != nullptr) {
            auto y = sin(t * m->dy);
            m->y = y;
        }
    }
}

};
