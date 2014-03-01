cmake_minimum_required (VERSION 2.6)
project (gl-unreal-world)
find_package(PkgConfig REQUIRED)

# configure packages
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
find_package(Log4Cxx REQUIRED)

include_directories (${LOG4CXX_INCLUDE_DIR})

# configure for C++11
ADD_DEFINITIONS("-std=c++0x")

# add the OpenGL library
include_directories ("${PROJECT_SOURCE_DIR}/src/modules/ogl")
add_subdirectory (src/modules/ogl)

# add the Unreal World library
include_directories ("${PROJECT_SOURCE_DIR}/src/modules/uwl")
add_subdirectory (src/modules/uwl)

# add the executable
add_executable (main src/main.cc)
target_link_libraries (main ogl uwl ${LOG4CXX_LIBRARIES} ${EXTRA_LIBS})

# copy resources
add_custom_command (TARGET main POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${PROJECT_SOURCE_DIR}/resources $<TARGET_FILE_DIR:main>/resources)

# add the install targets
install (TARGETS main DESTINATION bin)
install (DIRECTORY "${PROJECT_SOURCE_DIR}/resources" DESTINATION resources)
