#ifndef INC_OGLWIN_INPUT_MANAGER_H
#define INC_OGLWIN_INPUT_MANAGER_H

#ifndef __GLFW_INCLUDED__
#define __GLFW_INCLUDED__
#define GLFW_INCLUDE_GL_3
#define GL_GLEXT_PROTOTYPES 1
#include <GLFW/glfw3.h>
#endif

#include "oglwin_window_manager.h"
#include "uwlinf/uwlinf_message_queue.h"

#include <memory>

namespace oglwin {

class KeyReceiver {
public:
    virtual ~KeyReceiver() { }
    virtual void processKeyEvent(int key, int scancode, int action, int mods) = 0;
};

class InputManager {
public:
    InputManager(std::shared_ptr<WindowManager> windowManager, std::shared_ptr<uwlinf::MessageQueue> messageQueue)
        : _windowManager(windowManager),
          _messageQueue(messageQueue)
    { }

    virtual ~InputManager() { }

    virtual void initialize();

    virtual void finalize();

    virtual void processInput();

    virtual bool isKeyDown(int key);

    virtual void setKeyReceiver(std::shared_ptr<KeyReceiver> receiver);

    virtual void clearKeyReceiver();

public:
    static InputManager* current_instance;

private:
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

    void publishKeyCommand(int key);

    // ----------------------------------------------------------------------

    static void s_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
    std::shared_ptr<WindowManager> _windowManager;

    std::shared_ptr<uwlinf::MessageQueue> _messageQueue;

    std::shared_ptr<KeyReceiver> _keyReceiver;

    bool keys[512];
    bool mouseButtons[16];
    int modifiers;

};

};

#endif
