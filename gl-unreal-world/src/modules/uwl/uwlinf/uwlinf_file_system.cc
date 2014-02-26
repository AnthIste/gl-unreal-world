#include "uwlinf_file_system.h"

#include <iostream>

namespace uwlinf {

FileSystem::FileSystem()
{
}

FileSystem::~FileSystem()
{
}

void FileSystem::r_open_resource(std::string resourcePath, std::ifstream& file)
{
    std::string virtualPath = getResourcePath(resourcePath);
    file.open(virtualPath, std::ios::in);

    if (!file) {
        std::cerr << "r_open_resource failed for resource: "
                  << virtualPath
                  << std::endl;
    }
}

void FileSystem::r_open_binary_resource(std::string resourcePath, std::ifstream& file)
{
    std::string virtualPath = getResourcePath(resourcePath);
    file.open(virtualPath, std::ios::in | std::ios::binary);

    if (!file) {
        std::cerr << "r_open_binary_resource failed for resource: "
                  << virtualPath
                  << std::endl;
    }
}

void FileSystem::rw_open_resource(std::string resourcePath, std::fstream& file)
{
    std::string virtualPath = getResourcePath(resourcePath);
    file.open(virtualPath, std::ios::out);

    if (!file) {
        std::cerr << "rw_open_resource failed for resource: "
                  << virtualPath
                  << std::endl;
    }
}

void FileSystem::rw_open_binary_resource(std::string resourcePath, std::fstream& file)
{
    std::string virtualPath = getResourcePath(resourcePath);
    file.open(virtualPath, std::ios::out | std::ios::binary);

    if (!file) {
        std::cerr << "rw_open_binary_resource failed for resource: "
                  << virtualPath
                  << std::endl;
    }
}

std::string FileSystem::getResourcePath(std::string resourcePath) const
{
    return std::string("resources/") + resourcePath;
}

};
