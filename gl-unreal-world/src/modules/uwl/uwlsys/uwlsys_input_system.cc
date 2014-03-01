#include "uwlsys_input_system.h"
#include "uwlevt/commands.h"

using uwlinf::Message;

namespace uwlsys {

void InputSystem::initialize()
{
    _inputManager->setKeyReceiver(shared_from_this());
}

void InputSystem::finalize()
{
    _inputManager->clearKeyReceiver();
}

bool InputSystem::isKeyDown(KeyMap key)
{
    if (key < 0 || key >= 512) {
        return false;
    }

    return keys[key];
}

void InputSystem::tick(double t, double dt)
{
}

void InputSystem::processKeyEvent(int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS) {
        keys[key] = true;

        publishKeyCommand(key);
    }

    if (action == GLFW_RELEASE) {
        keys[key] = false;
    }
}

void InputSystem::publishKeyCommand(int key)
{
    switch (key) {
        case GLFW_KEY_ESCAPE:
        {
            _messageQueue->postMessage(
                std::unique_ptr<uwlevt::CommandExit>(new uwlevt::CommandExit())
            );
            break;
        }
    }
}

};
