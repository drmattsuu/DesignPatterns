#pragma once

#include <print>

#include "Component.h"

namespace Composite
{
/**
 * The Leaf is a basic element of a tree that doesn't have sub-elements.
 */
class Leaf final : public Component
{
public:
    void execute() override;
};

class Leaf1 final : public Component
{
public:
    void execute() override;
};

class Leaf2 final : public Component
{
public:
    void execute() override;
};

}  // namespace Composite

inline void Composite::Leaf::execute()
{
    std::println("Execute Leaf");
}

inline void Composite::Leaf1::execute()
{
    std::println("Execute Leaf1");
}

inline void Composite::Leaf2::execute()
{
    std::println("Execute Leaf2");
}
