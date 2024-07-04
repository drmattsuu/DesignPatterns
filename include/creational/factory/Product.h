#pragma once

#include <Util.h>

namespace Factory
{

/** The Product Interface
 * The Product declares the interface, which is common to all objects that can be produced by the creator and its
 * subclasses.
 */
class Product
{
    INTERFACE_CLASS(Product)
public:
    virtual void open() = 0;
};
}  // namespace Factory
