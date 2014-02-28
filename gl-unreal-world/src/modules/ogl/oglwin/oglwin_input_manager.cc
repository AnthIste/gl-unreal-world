#include "oglwin_input_manager.h"

using uwlman::Message;

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

// TODO: transparent key API
bool InputManager::isKeyDown(int key)
{
    if (key < 0 || key >= 512) {
        return false;
    }

    return keys[key];
}

void InputManager::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS) {
        keys[key] = true;

        std::unique_ptr<Message> message;
        _messageQueue->postMessage(std::move(message));
    }

    if (action == GLFW_RELEASE) {
        keys[key] = false;
    }
}

void InputManager::s_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    InputManager::current_instance->key_callback(window, key, scancode, action, mods);
}

};
