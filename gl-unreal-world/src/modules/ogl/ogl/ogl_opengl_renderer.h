#ifndef INC_GFX_RENDERER_H
#define INC_GFX_RENDERER_H

#ifndef __GLFW_INCLUDED__
#define __GLFW_INCLUDED__
#define GLFW_INCLUDE_GL_3
#define GL_GLEXT_PROTOTYPES 1
#include <GLFW/glfw3.h>
#endif

namespace ogl {

class OpenGLRenderer {
public:
    OpenGLRenderer() {}

    ~OpenGLRenderer();

    void initialize();

    void finalize();

    void clear_frame();

    void set_cull_render_mode();

    void render_colored_triangle(GLuint vbo, GLfloat dx, GLfloat dy);

    GLuint create_vbo();
};

};

#endif
