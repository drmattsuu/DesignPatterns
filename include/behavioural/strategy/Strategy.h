#pragma once

#include <Util.h>

namespace Strategy
{

/** The Strategy Interface
 * The Strategy interface is common to all concrete strategies. It declares a method the context uses to execute a
 * strategy.
 */
class Strategy
{
    INTERFACE_CLASS(Strategy)
public:

    virtual int execute(const int a, const int b) = 0;
};

}  // namespace Strategy
