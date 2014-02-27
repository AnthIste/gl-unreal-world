#ifndef INC_UWL_GAME_H
#define INC_UWL_GAME_H

#include "uwlman/uwlman_entity_manager.h"
#include "uwlsys/uwlsys_game_logic_system.h"
#include "uwlsys/uwlsys_gfx_system.h"
#include "uwlinf/uwlinf_file_system.h"
#include "uwlinf/uwlinf_clock.h"
#include "oglwin/oglwin_window_manager.h"
#include "oglwin/oglwin_input_manager.h"
#include "oglres/oglres_asset_manager.h"

#include <memory>

namespace uwl {

class Game {
public:
    Game();

    virtual ~Game();

    void initialize();

    void finalize();

    bool isDone();

    void tick();

private:
    std::shared_ptr<uwlman::EntityManager> _entityManager;

    std::shared_ptr<uwlsys::GameLogicSystem> _gameLogicSystem;

    std::shared_ptr<uwlsys::GfxSystem> _gfxSystem;

    std::shared_ptr<uwlinf::FileSystem> _fileSystem;

    std::shared_ptr<uwlinf::Clock> _clock;

    std::shared_ptr<oglwin::WindowManager> _windowManager;

    std::shared_ptr<oglwin::InputManager> _inputManager;

    std::shared_ptr<oglres::AssetManager> _assetManager;

};

};

#endif
