#include "uwlman_input_manager.h"

#ifndef __GLFW_INCLUDED__
#define __GLFW_INCLUDED__
#define GLFW_INCLUDE_GL_3
#define GL_GLEXT_PROTOTYPES 1
#include <GLFW/glfw3.h>
#endif

namespace uwlman {

InputManager::InputManager()
{
}

void InputManager::processInput()
{
}

// TODO: transparent key API
void InputManager::acceptKeyDown(int key, int scancode, int mods)
{
    if (key < 0 || key >= 512) {
        return;
    }

    modifiers = mods;
    keys[key] = true;
}

// TODO: transparent key API
void InputManager::acceptKeyUp(int key, int scancode, int mods)
{
    if (key < 0 || key >= 512) {
        return;
    }

    modifiers = mods;
    keys[key] = false;
}

// TODO: transparent mouse API
void InputManager::acceptMouseDown(int button, int mods)
{
    if (button < 0 || button >= 16) {
        return;
    }

    modifiers = mods;
    mouseButtons[button] = true;
}

// TODO: transparent mouse API
void InputManager::acceptMouseUp(int button, int mods)
{
    if (button < 0 || button >= 16) {
        return;
    }

    modifiers = mods;
    mouseButtons[button] = false;
}

// TODO: transparent mouse API
bool InputManager::isKeyDown(int key)
{
    if (key < 0 || key >= 512) {
        return false;
    }

    return keys[key];
}

};
