#if 0
#include "EcsWin.h"



ComponentMap ComponentStore::Clone(const ComponentMap& componentMap)
{
    ComponentMap map;

    for (auto& componentPair : componentMap)
    {
        auto[componentType, component] = componentPair;

        auto new_component = CreateComponent(componentType);
        component->CopyTo(new_component.get());
        map[componentType] = std::move(new_component);
    }

    return map;
}

void ComponentStore::Update(double)
{
    for (auto& components : m_components)
    {
        Destroyable::PruneFromContainer(&components.second);
    }
}

SharedComponent ComponentStore::CreateComponent(const detail::type_id& typeId)
{
    auto it = m_producers.find(typeId);

    fail_fast_if(it == m_producers.end(), "Invalid to create non-existant component");

    auto obj = it->second();
    m_components[typeId].push_back(obj);
    return obj;
}
#endif
