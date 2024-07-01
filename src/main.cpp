
#include "behavioural/strategy/Client.h"

#include <iostream>
#include <string>

int main(void)
{
    // Strategy Pattern
    Strategy::CalculatorClient strategyClient;
    std::cout << "Strategy Example:" << std::endl;
    strategyClient.run(Strategy::CalculatorClient::Action::Add, 3, 2);
    strategyClient.run(Strategy::CalculatorClient::Action::Subtract, 3, 2);
    // -

    return 0;
}
