#pragma once

namespace Strategy
{

/** The Strategy Interface
 * The Strategy interface is common to all concrete strategies. It declares a method the context uses to execute a
 * strategy.
 */

class Strategy
{
public:
    Strategy() = default;
    virtual ~Strategy() = default;

    Strategy(Strategy& rhs) = default;
    Strategy& operator=(const Strategy& rhs) = default;
    Strategy(Strategy&& rhs) = default;
    Strategy& operator=(Strategy&& rhs) = default;

    virtual int execute(const int a, const int b) = 0;
};

}  // namespace Strategy
