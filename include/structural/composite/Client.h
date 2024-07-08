#pragma once

#include <list>

#include "Component.h"
#include "Composite.h"
#include "Leaf.h"

namespace Composite
{
class Client
{
public:
    Client();
    void run() const;

private:
    std::list<ComponentPtr> m_components;
};
}  // namespace Composite

inline Composite::Client::Client()
{
    const auto leaf = std::make_shared<Leaf>();
    m_components.push_back(leaf);

    const auto composite = std::make_shared<Composite>();
    composite->add(std::make_shared<Leaf1>());
    composite->add(std::make_shared<Leaf2>());
    m_components.push_back(composite);
}

inline void Composite::Client::run() const
{
    for (const auto& component : m_components)
    {
        component->execute();
    }
}
