#include "uwlsys_gfx_system.h"

#include <iostream>

namespace uwlsys {

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

    init_window();
    init_renderer();

    _vbo = _renderer->create_vbo();
}

void GfxSystem::finalize()
{
    shutdown_renderer();
    destroy_window();
}

bool GfxSystem::windowCanClose()
{
    return glfwWindowShouldClose(_window);
}

void GfxSystem::tick(long t)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    render_scene();

    glfwSwapBuffers(_window);
    glfwPollEvents();
}

void GfxSystem::init_window()
{
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

    // Configure OpenGL context
    glfwMakeContextCurrent(_window);
}

void GfxSystem::destroy_window()
{
    glfwDestroyWindow(_window);
    glfwTerminate();
}

void GfxSystem::init_renderer()
{
    _renderer->initialize();
    _renderer->set_cull_render_mode();
}

void GfxSystem::shutdown_renderer()
{
    _renderer->finalize();
}

void GfxSystem::render_scene()
{
    _renderer->render_colored_triangle(_vbo, 0.0f, 0.0f);
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
