#ifndef INC_SYSTEMS_GFX_SYSTEM_H
#define INC_SYSTEMS_GFX_SYSTEM_H

#include "uwlsys_system.h"
#include "uwlman/uwlman_entity_manager.h"
#include "oglres/oglres_asset_manager.h"
#include "ogl/ogl_opengl_renderer.h"
#include "uwlec/uwlec_moveable.h"

#include <memory>

namespace uwlsys {

class GfxSystem : public uwlsys::System {
public:
    GfxSystem(std::shared_ptr<uwlman::EntityManager> entityManager,
              std::shared_ptr<oglres::AssetManager> assetManager)
        : uwlsys::System(entityManager),
          _entityManager(entityManager),
          _assetManager(assetManager)
    { }

    virtual ~GfxSystem();

    virtual void initialize();

    virtual void finalize();

    virtual void tick(double t, double dt);

private:
    void render_moveable(std::shared_ptr<uwlec::Moveable> m);

private:
    std::shared_ptr<uwlman::EntityManager> _entityManager;

    std::shared_ptr<oglres::AssetManager> _assetManager;

    std::shared_ptr<ogl::OpenGLRenderer> _renderer;

    // Temp testing data
    // GLuint leaks from OpenGL renderer's public API
    // The whole OpenGL API leaks... this isn't a problem
    // for pet projects but PIMPL is applicable
    GLuint _basicShader;
    GLuint _vbo;

};

};

#endif
