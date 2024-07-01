#pragma once

#include <exception>
#include <iostream>
#include <memory>
#include <string>

#include "Strategy.h"

namespace Strategy
{

/** The Context Class
 * The Context maintains a reference to one of the concrete strategies and communicates with this object only via the
 * strategy interface.
 */
class Context
{
public:
    void setStrategy(std::shared_ptr<Strategy> strategy) { m_currentStrategy = strategy; }

    int processData(int a, int b)
    {
        if (!m_currentStrategy)
        {
            throw std::runtime_error("Current Strategy is null.");
        }

        std::cout << "Processing the data a: " << a << " b: " << b << std::endl;
        return m_currentStrategy->execute(a, b);
    }

private:
    std::shared_ptr<Strategy> m_currentStrategy{nullptr};
};

}  // namespace Strategy
