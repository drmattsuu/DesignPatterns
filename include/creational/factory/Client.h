#pragma once

#include <memory>
#include <print>

#include "Factory.h"

namespace Factory
{
/**
 * Concrete product classes implement the Product interface in different ways.
 */
class Can final : public Product
{
public:
    void open() override { std::println("Opening the Can."); }
};

class Box final : public Product
{
public:
    void open() override { std::println("Opening the Box."); }
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

static void Run(const std::shared_ptr<Factory>& factory)
{
    std::println("Running Factory:");
    factory->createAndOpen();
}
}  // namespace Factory
