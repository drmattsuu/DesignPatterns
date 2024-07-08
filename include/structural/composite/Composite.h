#pragma once

#include <list>
#include <memory>
#include <print>

#include "Component.h"
#include "Leaf.h"

using ComponentPtr = std::shared_ptr<Composite::Component>;

namespace Composite
{
/**
 * The Composite (container) class is an element that has sub-elements: leaves or other containers. A container doesn't
 * know the concrete classes of its children. It works with all sub-elements only via the component interface.
 */
class Composite final : public Component
{
public:
    void execute() override;
    void add(const ComponentPtr& c);
    void remove(const ComponentPtr& c);
    [[nodiscard]] const std::list<ComponentPtr>& getChildren() const;

private:
    std::list<ComponentPtr> m_children;
};

}  // namespace Composite

inline void Composite::Composite::execute()
{
    std::println("Execute Composite");
    for (const auto& child : m_children)
    {
        std::print("  - ");
        child->execute();
    }
}

inline void Composite::Composite::add(const ComponentPtr& c)
{
    m_children.push_back(c);
}

inline void Composite::Composite::remove(const ComponentPtr& c)
{
    m_children.remove(c);
}

inline const std::list<ComponentPtr>& Composite::Composite::getChildren() const
{
    return m_children;
}
