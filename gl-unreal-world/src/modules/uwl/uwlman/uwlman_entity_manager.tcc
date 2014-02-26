// Template implementation of uwlman_entity_manager.h

#include <stdexcept>

namespace uwlman {

template <typename TComponent>
void EntityManager::addComponent(std::shared_ptr<uwlec::Entity> entity, std::shared_ptr<TComponent> component)
{
    auto key = typeid(TComponent).hash_code();

    component->id = newIdentity();
    _componentsById[component->id] = component;

    entity->components[key] = component->id;
}

template <typename TComponent>
void EntityManager::removeComponent(std::shared_ptr<uwlec::Entity> entity)
{
    auto key = typeid(TComponent).hash_code();

    entity->components.erase(key);
}

template <typename TComponent>
std::shared_ptr<TComponent> EntityManager::getComponent(std::shared_ptr<uwlec::Entity> entity) const
{
    try {
        auto key = typeid(TComponent).hash_code();
        auto componentId = entity->components.at(key);
        auto component = _componentsById.at(componentId);

        return std::static_pointer_cast<TComponent>(component);
    }
    catch (std::out_of_range) {
        return nullptr;
    }
}

};
