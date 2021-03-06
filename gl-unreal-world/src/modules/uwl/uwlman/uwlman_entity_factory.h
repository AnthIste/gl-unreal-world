#ifndef INC_UWLMAN_ENTITY_FACTORY_H
#define INC_UWLMAN_ENTITY_FACTORY_H

#include "uwlec/uwlec_entity.h"
#include "uwlman/uwlman_entity_manager.h"
#include "ogl/ogl_primitives.h"

#include <memory>

namespace uwlman {

enum EntityType {
    Guzzler,
    Wooter
};

class EntityFactory {
public:
    EntityFactory(std::shared_ptr<uwlman::EntityManager> entityManager)
        : _entityManager(entityManager)
    { }

    virtual ~EntityFactory() { }

    virtual std::shared_ptr<uwlec::Entity> createEntity(EntityType type, double x, double y);

private:
    std::shared_ptr<uwlec::Entity> createGuzzler(double x, double y);

    std::shared_ptr<uwlec::Entity> createWooter(double x, double y);

    void initializeMeshData();

    std::shared_ptr<ogl::Mesh1P> createMesh(EntityType type);

private:
    std::shared_ptr<uwlman::EntityManager> _entityManager;

    std::shared_ptr<ogl::Mesh1P> _guzzlerMesh;

    std::shared_ptr<ogl::Mesh1P> _wooterMesh;

};

};

#endif
