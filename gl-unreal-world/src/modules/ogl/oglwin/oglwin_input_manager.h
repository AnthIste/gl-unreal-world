#ifndef INC_OGLWIN_INPUT_MANAGER_H
#define INC_OGLWIN_INPUT_MANAGER_H

#ifndef __GLFW_INCLUDED__
#define __GLFW_INCLUDED__
#define GLFW_INCLUDE_GL_3
#define GL_GLEXT_PROTOTYPES 1
#include <GLFW/glfw3.h>
#endif

#include "oglwin_window_manager.h"
#include "uwlman/uwlman_message_queue.h"

#include <memory>

namespace oglwin {

class InputManager {
public:
    InputManager(std::shared_ptr<WindowManager> windowManager, std::shared_ptr<uwlman::MessageQueue> messageQueue)
        : _windowManager(windowManager),
          _messageQueue(messageQueue)
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
    std::shared_ptr<WindowManager> _windowManager;

    std::shared_ptr<uwlman::MessageQueue> _messageQueue;

    bool keys[512];
    bool mouseButtons[16];
    int modifiers;

};

};

#endif
