#ifndef INC_GAME_GAME_H
#define INC_GAME_GAME_H

#include "entity/entity_manager.h"
#include "systems/game_logic.h"
#include "systems/gfx_system.h"

#include <memory>

namespace ecsgame {

class Game {
public:
    Game();

    virtual ~Game();

    void initialize();

    void finalize();

    bool isDone();

    void tick();

private:
    std::shared_ptr<ecsentity::EntityManager> _entityManager;

    std::shared_ptr<ecssystems::GameLogicSystem> _gameLogicSystem;

    std::shared_ptr<ecssystems::GfxSystem> _gfxSystem;

};

};

#endif
