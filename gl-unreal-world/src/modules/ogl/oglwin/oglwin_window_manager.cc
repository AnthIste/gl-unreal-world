#include "oglwin_window_manager.h"

#include <iostream>

namespace oglwin {

// Used for GLFW static callback routing
extern WindowManager* WindowManager::current_instance;

WindowManager::WindowManager()
{
}

WindowManager::~WindowManager()
{
}

void WindowManager::createWindow(std::string title, unsigned int width, unsigned int height)
{
    WindowManager::current_instance = this;

    // Initialize error handler
    glfwSetErrorCallback(WindowManager::s_error_callback);

    // Initialize GLFW library
    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }

    // Set up a windowed OpenGL window
    _window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

    if (!_window)
    {
        // TODO: engine logging and error reporting
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Configure window hookpoints
    glfwSetWindowSizeCallback(_window, WindowManager::s_window_size_callback);

    // Configure OpenGL context
    glfwMakeContextCurrent(_window);
}

void WindowManager::closeWindow()
{
    glfwSetWindowShouldClose(_window, 1);
}

bool WindowManager::windowCanClose()
{
    return glfwWindowShouldClose(_window);
}

void WindowManager::redrawWindow()
{
    glfwSwapBuffers(_window);
    glfwPollEvents();
}

GLFWwindow* WindowManager::getGlfwWindow()
{
    return _window;
}

void WindowManager::window_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
}

void WindowManager::error_callback(int error, const char* description)
{
    std::cerr << description << std::endl;
}

// ----------------------------------------------------------------------
// Static callback routing
// ----------------------------------------------------------------------

void WindowManager::s_window_size_callback(GLFWwindow* window, int width, int height)
{
    WindowManager::current_instance->window_size_callback(window, width, height);
}

void WindowManager::s_error_callback(int error, const char* description)
{
    WindowManager::current_instance->error_callback(error, description);
}

};
