#pragma once

#include <memory>
#include <print>

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
    void setStrategy(const std::shared_ptr<Strategy>& strategy) { m_currentStrategy = strategy; }

    int processData(const int a, const int b) const
    {
        if (!m_currentStrategy)
        {
            throw std::runtime_error("Current Strategy is null.");
        }

        std::println("Processing the data a: {0} b: {1}", a, b);
        return m_currentStrategy->execute(a, b);
    }

private:
    std::shared_ptr<Strategy> m_currentStrategy{nullptr};
};

}  // namespace Strategy
