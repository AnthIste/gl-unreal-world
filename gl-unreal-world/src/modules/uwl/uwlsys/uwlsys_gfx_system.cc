#include "uwlsys_gfx_system.h"

#include <log4cxx/logger.h>

using namespace log4cxx;

using uwlec::Entity;
using uwlec::Moveable;
using uwlec::Renderable;
using uwlman::EntityManager;

namespace uwlsys {

GfxSystem::~GfxSystem()
{
}

void GfxSystem::initialize()
{
    _renderer->initialize();
    _renderer->set_cull_render_mode();

    _basicShader = _assetManager->loadShaderProgram("basic");
    //_vbo = _renderer->create_vbo();
}

void GfxSystem::finalize()
{
    _renderer->finalize();
}

void GfxSystem::tick(double t, double dt)
{
    _renderer->render_clear_frame();

    EntityManager::EntitySet allEntities = _entityManager->allEntities();

    for (auto entity : allEntities) {
        auto m = _entityManager->getComponent<Moveable>(entity);
        auto r = _entityManager->getComponent<Renderable>(entity);

        if (m != nullptr && r != nullptr) {
            render_entity(m, r);
        }
    }
}

void GfxSystem::render_entity(std::shared_ptr<uwlec::Moveable> m, std::shared_ptr<uwlec::Renderable> r)
{
    auto mesh = r->mesh;

    if (!_vbo) {
        _vbo = _renderer->createVBO_Mesh1P(*mesh);
    }

    _renderer->set_shader_program(_basicShader);
    _renderer->set_uniform_2f(_basicShader, "offset", m->x, m->y);
    _renderer->set_uniform_4f(_basicShader, "color", 0.5, 1.0, 0.0, 0.0);

    //_renderer->renderMesh1P(*mesh);
    _renderer->render_triangles(_vbo, 1);
}

};
