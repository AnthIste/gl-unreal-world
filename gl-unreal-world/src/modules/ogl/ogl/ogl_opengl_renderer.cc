#include "ogl_opengl_renderer.h"

namespace ogl {

OpenGLRenderer::~OpenGLRenderer()
{
}

void OpenGLRenderer::initialize()
{
}

void OpenGLRenderer::finalize()
{
}

void OpenGLRenderer::render_clear_frame()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLRenderer::set_cull_render_mode()
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CW);
}

void OpenGLRenderer::render_triangles(GLuint vbo, int nTriangles)
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 3 * nTriangles);

    glDisableVertexAttribArray(0);
    glUseProgram(0);
}

void OpenGLRenderer::set_shader_program(GLuint program)
{
    glUseProgram(program);
}

void OpenGLRenderer::set_uniform_2f(GLuint shaderProgram, std::string uniform, GLfloat x, GLfloat y)
{
    GLuint uniformLocation = glGetUniformLocation(shaderProgram, uniform.c_str());
    glUniform2f(uniformLocation, x, y);
}

void OpenGLRenderer::set_uniform_4f(GLuint shaderProgram, std::string uniform, GLfloat m, GLfloat x, GLfloat y, GLfloat z)
{
    GLuint uniformLocation = glGetUniformLocation(shaderProgram, uniform.c_str());
    glUniform4f(uniformLocation, m, x, y, z);
}

GLuint OpenGLRenderer::create_vbo()
{
    GLuint bufferObject;
    const float vertexData[] = {
        // Triangle data:
        0.0f,    0.5f, 0.0f, 1.0f, // (Vec4)
        0.5f, -0.366f, 0.0f, 1.0f, // (Vec4)
        -0.5f, -0.366f, 0.0f, 1.0f, // (Vec4)

        // Color data:
        1.0f,    0.0f, 0.0f, 1.0f, // (Vec4)
        0.0f,    1.0f, 0.0f, 1.0f, // (Vec4)
        0.0f,    0.0f, 1.0f, 1.0f, // (Vec4)
    };

    glGenBuffers(1, &bufferObject);

    glBindBuffer(GL_ARRAY_BUFFER, bufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    return bufferObject;
}

};
