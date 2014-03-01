#include "oglwin_input_manager.h"
#include "uwlevt/commands.h"

using uwlinf::Message;

namespace oglwin {

// Used for GLFW static callback routing
extern InputManager* InputManager::current_instance;

void InputManager::initialize()
{
    InputManager::current_instance = this;

    glfwSetKeyCallback(_windowManager->getGlfwWindow(), InputManager::s_key_callback);
}

void InputManager::finalize()
{
}

void InputManager::processInput()
{
}

bool InputManager::isKeyDown(int key)
{
    if (key < 0 || key >= 512) {
        return false;
    }

    return keys[key];
}

void InputManager::setKeyReceiver(std::shared_ptr<KeyReceiver> receiver)
{
    _keyReceiver = receiver;
}

void InputManager::clearKeyReceiver()
{
    _keyReceiver = nullptr;
}

void InputManager::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (_keyReceiver != nullptr) {
        _keyReceiver->processKeyEvent(key, scancode, action, mods);
    }

    if (action == GLFW_PRESS) {
        keys[key] = true;

        publishKeyCommand(key);
    }

    if (action == GLFW_RELEASE) {
        keys[key] = false;
    }
}

void InputManager::publishKeyCommand(int key)
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

void InputManager::s_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    InputManager::current_instance->key_callback(window, key, scancode, action, mods);
}

};
