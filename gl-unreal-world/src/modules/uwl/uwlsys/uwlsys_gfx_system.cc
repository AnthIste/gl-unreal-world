#include "uwlsys_gfx_system.h"

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
        auto r = _entityManager->getComponent<Renderable>(entity);

        if (m != nullptr && r != nullptr) {
            render_entity(m, r);
        }
    }
}

void GfxSystem::render_entity(std::shared_ptr<uwlec::Moveable> m, std::shared_ptr<uwlec::Renderable> r)
{
    GLfloat ca = 0.5;
    GLfloat cr = ((r->color >> 16) & 0xFF) / 255.0;
    GLfloat cg = ((r->color >> 8) & 0xFF) / 255.0;
    GLfloat cb = ((r->color >> 0) & 0xFF) / 255.0;

    _renderer->set_shader_program(_basicShader);
    _renderer->set_uniform_2f(_basicShader, "offset", m->x, m->y);
    _renderer->set_uniform_4f(_basicShader, "color", ca, cr, cg, cb);

    _renderer->render_triangles(_vbo, 1);
}

};
