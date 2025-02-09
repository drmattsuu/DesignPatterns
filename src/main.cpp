
#include "behavioural/strategy/Client.h"
#include "creational/factory/Client.h"
#include "structural/composite/Client.h"

#include <print>

int main()
{
    // Creation
    // Factory
    try
    {
        std::cout << "Factory Example:\n";
        const auto canFactory = std::make_shared<Factory::CanFactory>();
        const auto boxFactory = std::make_shared<Factory::BoxFactory>();

        Factory::Run(canFactory);
        Factory::Run(boxFactory);
    }
    catch (std::exception& ex)
    {
        std::println("Exception: {0}", ex.what());
        return 1;
    }

    // Structural
    // Composite
    try
    {
        std::cout << "Composite Example:\n";
        const Composite::Client compositeClient;
        compositeClient.run();
    }
    catch (std::exception& ex)
    {
        std::println("Exception: {0}", ex.what());
        return 1;
    }

    // Behavioural
    // Strategy Pattern
    try
    {
        std::cout << "Strategy Example:\n";
        Strategy::CalculatorClient strategyClient;
        strategyClient.run(Strategy::CalculatorClient::Action::Add, 3, 2);
        strategyClient.run(Strategy::CalculatorClient::Action::Subtract, 3, 2);
    }
    catch (std::exception& ex)
    {
        std::println("Exception: {0}", ex.what());
        return 1;
    }
    // -

    return 0;
}
