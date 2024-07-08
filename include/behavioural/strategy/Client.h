#pragma once

#include <memory>
#include <print>

#include "Context.h"
#include "Strategy.h"

namespace Strategy
{

/** The Concrete Strategy Classes
 * Concrete Strategies implement different variations of an algorithm the context uses.
 * A more complex example may look like various kinds of routing algorithm to calculate a path from A to B, for example
 * A*, Dijkstra's etc.
 */
class AddStrategy final : public Strategy
{
public:
    int execute(const int a, const int b) override
    {
        std::println("Running add strategy.");
        return a + b;
    }
};

class SubtractStrategy final : public Strategy
{
public:
    int execute(const int a, const int b) override
    {
        std::println("Running subtract strategy.");
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
    enum class Action
    {
        Add,
        Subtract
    };

    void run(const Action action, const int a, const int b)
    {
        const auto addStrategy = std::make_shared<AddStrategy>();
        const auto subtractStrategy = std::make_shared<SubtractStrategy>();

        switch (action)
        {
            case Action::Add:
                m_myContext.setStrategy(addStrategy);
                break;
            case Action::Subtract:
                m_myContext.setStrategy(subtractStrategy);
                break;
        }

        const int result = m_myContext.processData(a, b);

        std::println("Result: {0}", result);
    }

private:
    Context m_myContext;
};

}  // namespace Strategy
