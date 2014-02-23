////////////////////////////////////////////////////////////////
// Program Boostrapper
//
// Responsibilities:
//  - Create a window
//  - Set up window loop
//  - Initialize subsystems
//  - Begin subsystem execution
//
// This file is just for starting up the program and
// interacting with the system environment. The rest of the
// execution should be deferred to subsystems.
////////////////////////////////////////////////////////////////

#include "entity/entity.h"
#include "entity/entity_manager.h"
#include "systems/game_logic.h"

#ifndef __GLFW_INCLUDED__
#define __GLFW_INCLUDED__
#define GLFW_INCLUDE_GL_3
#define GL_GLEXT_PROTOTYPES 1
#include <GLFW/glfw3.h>
#endif

#include <memory>
#include <iostream>
#include <cstdlib>

using ecsentity::Entity;
using ecsentity::EntityManager;
using ecssystems::GameLogicSystem;

const char* WindowTitle = "The Unreal World";
const int WindowWidth = 640;
const int WindowHeight = 640;

static void init_opengl(GLFWwindow* window);
static void render_scene();
static void window_size_callback(GLFWwindow* window, int width, int height);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void error_callback(int error, const char* description);

int main()
{
    GLFWwindow* window;

    // Initialize error handler
    glfwSetErrorCallback(error_callback);

    // Initialize GLFW library
    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }

    // Set up a windowed OpenGL window
    window = glfwCreateWindow(WindowWidth, WindowHeight, WindowTitle, NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Configure window hookpoints
    glfwSetWindowSizeCallback(window, window_size_callback);
    glfwSetKeyCallback(window, key_callback);

    // Initialize OpenGL
    init_opengl(window);

    // Initialize game engine
    auto entityManager = std::make_shared<EntityManager>();
    auto gameLogicSystem = std::make_shared<GameLogicSystem>(entityManager);

    // Initialize entities
    auto shipEntity = std::make_shared<Entity>();

    // Initialize systems
    entityManager->registerEntity(shipEntity);
    entityManager->publishChanges();

    // Enter main window loop
    while (!glfwWindowShouldClose(window))
    {
        render_scene();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

static void init_opengl(GLFWwindow* window)
{
    glfwMakeContextCurrent(window);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CW);
}

static void render_scene()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

static void window_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
}

static void error_callback(int error, const char* description)
{
    std::cerr << description << std::endl;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}
