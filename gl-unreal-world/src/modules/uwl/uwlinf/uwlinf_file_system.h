#ifndef INC_UWLINF_FILE_SYSTEM_H
#define INC_UWLINF_FILE_SYSTEM_H

#include <fstream>
#include <string>

namespace uwlinf {

/// <summary>
/// Virtual file system interface
/// </summary>
class FileSystem {
public:
    FileSystem();

    virtual ~FileSystem();

    virtual void r_open_resource(std::string resourcePath, std::ifstream& file);

    virtual void r_open_binary_resource(std::string resourcePath, std::ifstream& file);

    virtual void rw_open_resource(std::string resourcePath, std::fstream& file);

    virtual void rw_open_binary_resource(std::string resourcePath, std::fstream& file);

private:
    std::string getResourcePath(std::string resourcePath) const;

};

};

#endif
