#include "shader_utils.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// Adapted from http://stackoverflow.com/q/2602013/761648
std::string load_shader_from_file(std::string filename)
{
    std::ifstream in(filename.c_str(), std::ios::in | std::ios::binary);

    if (in)
    {
        std::string contents;

        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());

        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());

        in.close();

        return contents;
    }

    std::cerr << "Could not open " << filename << std::endl;

    return "";
}

// Shader link stage
GLuint create_shader_program(const std::vector<GLuint> &shaderList)
{
    // Create OpenGL object
    GLuint program = glCreateProgram();

    // Tell OpenGL about our shader objects
    for(size_t iLoop = 0; iLoop < shaderList.size(); iLoop++)
        glAttachShader(program, shaderList[iLoop]);

    // Link them all into one program
    glLinkProgram(program);

    // Handle errors
    GLint status;
    glGetProgramiv (program, GL_LINK_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);

        GLchar *strInfoLog = new GLchar[infoLogLength + 1];
        glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);

        std::cerr <<  "Linker failure: " << strInfoLog << std::endl;
        delete[] strInfoLog;
    }

    // The shaders are linked already, we can tell OpenGL to
    // forget about them
    for(size_t iLoop = 0; iLoop < shaderList.size(); iLoop++)
        glDetachShader(program, shaderList[iLoop]);

    return program;
}

// Shader compile stage
GLuint create_shader(GLenum eShaderType, const std::string &strShaderFile)
{
    // Create OpenGL object
    GLuint shader = glCreateShader(eShaderType);

    const char *strFileData = strShaderFile.c_str();
    glShaderSource(shader, 1, &strFileData, NULL);

    // Turn the text shader into a compiled binary object
    glCompileShader(shader);

    // Handle errors
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

        GLchar *strInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);

        const char *strShaderType = NULL;
        switch(eShaderType)
        {
            case GL_VERTEX_SHADER: strShaderType = "vertex"; break;
            case GL_GEOMETRY_SHADER: strShaderType = "geometry"; break;
            case GL_FRAGMENT_SHADER: strShaderType = "fragment"; break;
        }

        std::cerr <<  "Compile failure in " << strShaderType << " shader:" << std::endl << strInfoLog << "%s" << std::endl;
        delete[] strInfoLog;
    }

    return shader;
}
