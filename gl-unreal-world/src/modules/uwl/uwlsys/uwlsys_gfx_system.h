#ifndef INC_SYSTEMS_GFX_SYSTEM_H
#define INC_SYSTEMS_GFX_SYSTEM_H

#include "uwlsys_system.h"
#include "uwlman/uwlman_entity_manager.h"
#include "ogl/ogl_opengl_renderer.h"

#include <memory>

namespace uwlsys {

class GfxSystem : public uwlsys::System {
public:
    GfxSystem(std::shared_ptr<uwlman::EntityManager> entityManager)
        : uwlsys::System(entityManager)
        { }

    virtual ~GfxSystem();

    virtual void initialize();

    virtual void finalize();

    virtual void tick(long t);

private:
    void render_scene();

private:
    std::shared_ptr<ogl::OpenGLRenderer> _renderer;

    // Temp testing data
    GLuint _vbo;

};

};

#endif
