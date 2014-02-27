#ifndef INC_OGLWIN_WINDOW_MANAGER_H
#define INC_OGLWIN_WINDOW_MANAGER_H

#ifndef __GLFW_INCLUDED__
#define __GLFW_INCLUDED__
#define GLFW_INCLUDE_GL_3
#define GL_GLEXT_PROTOTYPES 1
#include <GLFW/glfw3.h>
#endif

#include <memory>
#include <string>

namespace oglwin {

class WindowManager {
public:
    WindowManager();

    virtual ~WindowManager();

    virtual void createWindow(std::string title, unsigned int width, unsigned int height);

    virtual void closeWindow();

    virtual bool windowCanClose();

    virtual void redrawWindow();

    virtual GLFWwindow* getGlfwWindow();

public:
    static WindowManager* current_instance;

private:
    void window_size_callback(GLFWwindow* window, int width, int height);

    void error_callback(int error, const char* description);

    // ----------------------------------------------------------------------

    static void s_window_size_callback(GLFWwindow* window, int width, int height);

    static void s_error_callback(int error, const char* description);

private:
    GLFWwindow* _window;

};

};

#endif
