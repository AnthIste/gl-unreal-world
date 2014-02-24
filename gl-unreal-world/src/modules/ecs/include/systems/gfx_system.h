#ifndef INC_SYSTEMS_GFX_SYSTEM_H
#define INC_SYSTEMS_GFX_SYSTEM_H

#include "system/system.h"
#include "gfx/renderer.h"

#ifndef __GLFW_INCLUDED__
#define __GLFW_INCLUDED__
#define GLFW_INCLUDE_GL_3
#define GL_GLEXT_PROTOTYPES 1
#include <GLFW/glfw3.h>
#endif

#include <memory>

namespace ecssystems {

class GfxSystem : public ecssystem::System {
public:
    GfxSystem(std::shared_ptr<ecsentity::EntityManager> entityManager)
        : ecssystem::System(entityManager)
        { }

    virtual ~GfxSystem();

    virtual void initialize();

    virtual void finalize();

    virtual bool windowCanClose();

    virtual void tick(long t);

public:
    static GfxSystem* current_instance;

private:
    void init_window();

    void init_renderer();

    void destroy_window();

    void shutdown_renderer();

    void render_scene();

    void window_size_callback(GLFWwindow* window, int width, int height);

    void error_callback(int error, const char* description);

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

    // ----------------------------------------------------------------------

    static void s_window_size_callback(GLFWwindow* window, int width, int height);

    static void s_error_callback(int error, const char* description);

    static void s_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
    GLFWwindow* _window;

    std::shared_ptr<ecsgfx::OpenGLRenderer> _renderer;

    // Temp testing data
    GLuint _vbo;

};

};

#endif
