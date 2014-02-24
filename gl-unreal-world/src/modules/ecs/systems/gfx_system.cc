#include "systems/gfx_system.h"

#include <iostream>

namespace ecssystems {

// Used for GLFW static callback routing
extern GfxSystem* GfxSystem::current_instance;

const char* WindowTitle = "The Unreal World";
const int WindowWidth = 640;
const int WindowHeight = 640;

GfxSystem::~GfxSystem()
{
}

void GfxSystem::initialize()
{
    GfxSystem::current_instance = this;

    // Initialize error handler
    glfwSetErrorCallback(GfxSystem::s_error_callback);

    // Initialize GLFW library
    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }

    // Set up a windowed OpenGL window
    _window = glfwCreateWindow(WindowWidth, WindowHeight, WindowTitle, NULL, NULL);

    if (!_window)
    {
        // TODO: engine logging and error reporting
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Configure window hookpoints
    glfwSetWindowSizeCallback(_window, GfxSystem::s_window_size_callback);
    glfwSetKeyCallback(_window, GfxSystem::s_key_callback);

    // Initialize OpenGL
    init_opengl();
}

void GfxSystem::finalize()
{
    glfwDestroyWindow(_window);
    glfwTerminate();
}

bool GfxSystem::windowCanClose()
{
    return glfwWindowShouldClose(_window);
}

void GfxSystem::tick(long t)
{
    render_scene();

    glfwSwapBuffers(_window);
    glfwPollEvents();
}

void GfxSystem::init_opengl()
{
    glfwMakeContextCurrent(_window);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CW);
}

void GfxSystem::render_scene()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void GfxSystem::window_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
}

void GfxSystem::error_callback(int error, const char* description)
{
    std::cerr << description << std::endl;
}

// TODO: move to input system
void GfxSystem::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

// ----------------------------------------------------------------------
// Static callback routing
// ----------------------------------------------------------------------

void GfxSystem::s_window_size_callback(GLFWwindow* window, int width, int height)
{
    GfxSystem::current_instance->window_size_callback(window, width, height);
}

void GfxSystem::s_error_callback(int error, const char* description)
{
    GfxSystem::current_instance->error_callback(error, description);
}

void GfxSystem::s_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    GfxSystem::current_instance->key_callback(window, key, scancode, action, mods);
}

};
