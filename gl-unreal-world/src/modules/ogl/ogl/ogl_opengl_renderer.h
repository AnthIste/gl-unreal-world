#ifndef INC_OGL_OPENGL_RENDERER_H
#define INC_OGL_OPENGL_RENDERER_H

#ifndef __GLFW_INCLUDED__
#define __GLFW_INCLUDED__
#define GLFW_INCLUDE_GL_3
#define GL_GLEXT_PROTOTYPES 1
#include <GLFW/glfw3.h>
#endif

#include <string>

namespace ogl {

class OpenGLRenderer {
public:
    OpenGLRenderer() {}

    ~OpenGLRenderer();

    void initialize();

    void finalize();

    void set_cull_render_mode();

    void set_shader_program(GLuint program);

    void set_uniform_2f(GLuint shaderProgram, std::string uniform, GLfloat x, GLfloat y);

    void render_clear_frame();

    void render_triangles(GLuint vbo, int nTriangles);

    GLuint create_vbo();
};

};

#endif
