#pragma once

#include <memory>

#include "Factory.h"

namespace Factory
{
/**
 * Concrete product classes implement the Product interface in different ways.
 */
class Can final : public Product
{
public:
    void open() override { std::cout << "Opening the Can.\n"; }
};

class Box final : public Product
{
public:
    void open() override { std::cout << "Opening the Box.\n"; }
};

/**
 * Concrete Factory classes implement specific factories for different concrete products.
 */
class CanFactory final : public Factory
{
public:
    std::shared_ptr<Product> createProduct() override { return std::make_shared<Can>(); }
};

class BoxFactory final : public Factory
{
public:
    std::shared_ptr<Product> createProduct() override { return std::make_shared<Box>(); }
};

/**
 * 
 */
class Client
{
public:
    static void run(const std::shared_ptr<Factory>& factory)
    {
        std::cout << "Running Factory:\n";
        factory->createAndOpen();
    }
};
}  // namespace Factory
