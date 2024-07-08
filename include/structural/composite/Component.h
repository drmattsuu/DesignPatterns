#pragma once

#include <Util.h>

namespace Composite
{
/**
 * The Component interface describes operations that are common to both simple and complex elements of the tree.
 */
class Component
{
    INTERFACE_CLASS(Component)
public:
    virtual void execute() = 0;
};
}  // namespace Composite
