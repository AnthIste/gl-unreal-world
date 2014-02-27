#include "uwlsys_gfx_system.h"

using uwlec::Entity;
using uwlec::Moveable;
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
    _vbo = _renderer->create_vbo();
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

        if (m != nullptr) {
            render_moveable(m);
        }
    }
}

void GfxSystem::render_moveable(std::shared_ptr<uwlec::Moveable> m)
{
    _renderer->set_shader_program(_basicShader);
    _renderer->set_uniform_2f(_basicShader, "offset", m->x, m->y);
    _renderer->render_triangles(_vbo, 1);
}

};
