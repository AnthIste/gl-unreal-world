#ifndef INC_UWL_GAME_H
#define INC_UWL_GAME_H

#include "uwlman/uwlman_message_receiver.h"

#include "uwlman/uwlman_entity_manager.h"
#include "uwlman/uwlman_entity_factory.h"
#include "uwlman/uwlman_event_manager.h"
#include "uwlsys/uwlsys_game_logic_system.h"
#include "uwlsys/uwlsys_input_system.h"
#include "uwlsys/uwlsys_gfx_system.h"
#include "uwlinf/uwlinf_message_queue.h"
#include "uwlinf/uwlinf_file_system.h"
#include "uwlinf/uwlinf_clock.h"
#include "uwlinf/uwlinf_timestep.h"
#include "oglwin/oglwin_window_manager.h"
#include "oglwin/oglwin_input_manager.h"
#include "oglres/oglres_asset_manager.h"

#include <memory>

namespace uwl {

class Game : public uwlman::MessageReceiver {
public:
    Game();

    virtual ~Game();

    virtual void initialize();

    virtual void finalize();

    virtual bool isDone();

    virtual void tick();

    virtual void receiveMessage(std::shared_ptr<uwlinf::Message> message);

private:
    void subscribeEvents();

private:
    std::shared_ptr<uwlman::EntityManager> _entityManager;

    std::shared_ptr<uwlman::EntityFactory> _entityFactory;

    std::shared_ptr<uwlman::EventManager> _eventManager;

    std::shared_ptr<uwlsys::GameLogicSystem> _gameLogicSystem;

    std::shared_ptr<uwlsys::InputSystem> _inputSystem;

    std::shared_ptr<uwlsys::GfxSystem> _gfxSystem;

    std::shared_ptr<uwlinf::MessageQueue> _messageQueue;

    std::shared_ptr<uwlinf::FileSystem> _fileSystem;

    std::shared_ptr<uwlinf::Clock> _clock;

    std::shared_ptr<uwlinf::TimeStep> _timeStep;

    std::shared_ptr<oglwin::WindowManager> _windowManager;

    std::shared_ptr<oglwin::InputManager> _inputManager;

    std::shared_ptr<oglres::AssetManager> _assetManager;

};

};

#endif
