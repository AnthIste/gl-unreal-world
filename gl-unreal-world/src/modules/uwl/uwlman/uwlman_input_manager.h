#ifndef INC_UWLMAN_INPUT_MANAGER_H
#define INC_UWLMAN_INPUT_MANAGER_H

#ifndef __GLFW_INCLUDED__
#define __GLFW_INCLUDED__
#define GLFW_INCLUDE_GL_3
#define GL_GLEXT_PROTOTYPES 1
#include <GLFW/glfw3.h>
#endif

#include <memory>

#include "oglwin/oglwin_window_manager.h"

// TODO: move to ogl module
namespace uwlman {

class InputManager {
public:
    InputManager(std::shared_ptr<oglwin::WindowManager> windowManager)
        : _windowManager(windowManager)
    { }

    virtual ~InputManager() { }

    virtual void initialize();

    virtual void finalize();

    virtual void processInput();

    // TODO: transparent mouse API
    virtual bool isKeyDown(int key);

public:
    static InputManager* current_instance;

private:
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

    // ----------------------------------------------------------------------

    static void s_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
    std::shared_ptr<oglwin::WindowManager> _windowManager;

    bool keys[512];
    bool mouseButtons[16];
    int modifiers;

};

};

#endif
