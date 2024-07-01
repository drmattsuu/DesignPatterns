#pragma once

#include <exception>
#include <iostream>
#include <memory>
#include <string>

#include "Context.h"
#include "Strategy.h"

namespace Strategy
{

/** The Concrete Strategy Classes
 * Concrete Strategies implement different variations of an algorithm the context uses.
 * A more complex example may look like various kinds of routing algorythm to calculate a path from A to B, for example
 * A*, Dijkstra's etc.
 */
class AddStrategy : public Strategy
{
public:
    AddStrategy() = default;
    virtual ~AddStrategy() = default;

    virtual int execute(int a, int b) override
    {
        std::cout << "Running add strategy." << std::endl;
        return a + b;
    }
};

class SubtractStrategy : public Strategy
{
public:
    SubtractStrategy() = default;
    virtual ~SubtractStrategy() = default;

    virtual int execute(int a, int b) override
    {
        std::cout << "Running subtract strategy." << std::endl;
        return a - b;
    }
};

/** The Client Class
 * The Client creates a specific strategy object and passes it to the context. The context exposes a setter which lets
 * clients replace the strategy associated with the context at runtime.
 */

class CalculatorClient
{
public:
    CalculatorClient() = default;
    ~CalculatorClient() = default;

    enum class Action
    {
        Add,
        Subtract
    };

    void run(Action action, int a, int b)
    {
        auto addStrategy = std::make_shared<AddStrategy>(AddStrategy());
        auto subtractStrategy = std::make_shared<SubtractStrategy>(SubtractStrategy());

        int result = 0;

        switch (action)
        {
            case Action::Add:
                m_myContext.setStrategy(addStrategy);
                break;
            case Action::Subtract:
                m_myContext.setStrategy(subtractStrategy);
                break;
            default:
                throw std::runtime_error("Unknown Action.");
        }

        result = m_myContext.processData(a, b);

        std::cout << "Result: " << result << std::endl;
    }

private:
    Context m_myContext;
};

}  // namespace Strategy
