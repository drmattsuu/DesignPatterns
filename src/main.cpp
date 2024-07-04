
#include "behavioural/strategy/Client.h"
#include "creational/factory/Client.h"
#include "creational/factory/Factory.h"

#include <iostream>

int main()
{
    // Creation
    // Factory
    try
    {
        std::cout << "Factory Example:\n";
        const auto canFactory = std::make_shared<Factory::CanFactory>();
        const auto boxFactory = std::make_shared<Factory::BoxFactory>();

        Factory::Client factoryClient;
        factoryClient.run(canFactory);
        factoryClient.run(boxFactory);
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << "\n";
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
        std::cout << ex.what() << "\n";
        return 1;
    }
    // -

    return 0;
}
