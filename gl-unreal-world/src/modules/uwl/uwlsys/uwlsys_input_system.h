#ifndef INC_UWLSYS_INPUT_SYSTEM_H
#define INC_UWLSYS_INPUT_SYSTEM_H

#include "uwlsys_system.h"
#include "oglwin/oglwin_input_manager.h"
#include "uwlinf/uwlinf_message_queue.h"

namespace uwlsys {

enum KeyMap {
    MoveForward = GLFW_KEY_W,
    MoveBackward = GLFW_KEY_S,
    MoveLeft = GLFW_KEY_A,
    MoveRight = GLFW_KEY_D,
    Throw = GLFW_KEY_SPACE,
    Exit = GLFW_KEY_ESCAPE,
};

class InputSystem : public uwlsys::System,
                    public oglwin::KeyReceiver,
                    public std::enable_shared_from_this<InputSystem> {
public:
    InputSystem(
        std::shared_ptr<uwlman::EntityManager> entityManager,
        std::shared_ptr<oglwin::InputManager> inputManager,
        std::shared_ptr<uwlinf::MessageQueue> messageQueue)
    :
        uwlsys::System(entityManager),
        oglwin::KeyReceiver(),
        std::enable_shared_from_this<InputSystem>(),
        _inputManager(inputManager),
        _messageQueue(messageQueue)
    { }

    virtual ~InputSystem() { }

    virtual void initialize();

    virtual void finalize();

    virtual bool isKeyDown(KeyMap key);

    virtual void tick(double t, double dt);

    virtual void processKeyEvent(int key, int scancode, int action, int mods);

private:
    void publishKeyCommand(int key);

private:
    std::shared_ptr<oglwin::InputManager> _inputManager;

    std::shared_ptr<uwlinf::MessageQueue> _messageQueue;

    bool keys[512];
    bool mouseButtons[16];
    int modifiers;
};

};

#endif
