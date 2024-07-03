
#include "behavioural/strategy/Client.h"

#include <iostream>

int main(void)
{
    // Strategy Pattern
    try
    {
        Strategy::CalculatorClient strategyClient;
        std::cout << "Strategy Example:\n";
        strategyClient.run(Strategy::CalculatorClient::Action::Add, 3, 2);
        strategyClient.run(Strategy::CalculatorClient::Action::Subtract, 3, 2);
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << "\n";
        return 1;
    }
    // -



    return 0;
}
