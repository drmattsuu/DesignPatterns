#pragma once

#include <iostream>
#include <memory>

#include "Product.h"
#include <Util.h>

namespace Factory
{
/** The Factory Interface
 * The factory declares a method that returns new Product objects
 */
class Factory
{
    INTERFACE_CLASS(Factory)
public:
    void createAndOpen()
    {
        const auto product = createProduct();
        product->open();
    }

    virtual std::shared_ptr<Product> createProduct() = 0;
};

}  // namespace Factory
