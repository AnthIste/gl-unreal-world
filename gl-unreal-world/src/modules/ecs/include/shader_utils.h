#ifndef INC_SHADER_UTILS_H
#define INC_SHADER_UTILS_H

#ifndef __GLFW_INCLUDED__
#define __GLFW_INCLUDED__
#define GLFW_INCLUDE_GL_3
#define GL_GLEXT_PROTOTYPES 1
#include <GLFW/glfw3.h>
#endif

#include <string>
#include <vector>

std::string load_shader_from_file(std::string filename);
GLuint create_shader_program(const std::vector<GLuint> &shaderList);
GLuint create_shader(GLenum eShaderType, const std::string &strShaderFile);

#endif
