#ifndef INC_OGLRES_ASSET_MANAGER_H
#define INC_OGLRES_ASSET_MANAGER_H

#ifndef __GLFW_INCLUDED__
#define __GLFW_INCLUDED__
#define GLFW_INCLUDE_GL_3
#define GL_GLEXT_PROTOTYPES 1
#include <GLFW/glfw3.h>
#endif

#include "uwlinf/uwlinf_file_system.h"

#include <memory>
#include <vector>

namespace oglres {

class AssetManager {
public:
    AssetManager(std::shared_ptr<uwlinf::FileSystem> fileSystem)
        : _fileSystem(fileSystem)
    { }

    virtual ~AssetManager();

    virtual GLuint loadShaderProgram(std::string shaderName);

private:
    std::string loadShaderString(std::string shaderFile);

    GLuint create_shader_program(const std::vector<GLuint> &shaderList);

    GLuint create_shader(GLenum eShaderType, const std::string &strShaderFile);


private:
    std::shared_ptr<uwlinf::FileSystem> _fileSystem;

};

};

#endif
