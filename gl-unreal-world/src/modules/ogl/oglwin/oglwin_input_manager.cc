#include "oglwin_input_manager.h"

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
}

void InputManager::s_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    InputManager::current_instance->key_callback(window, key, scancode, action, mods);
}

};
