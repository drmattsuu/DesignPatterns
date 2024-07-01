#pragma once

#include <iostream>
#include <string>

namespace Strategy
{

/** The Strategy Interface
 * The Strategy interface is common to all concrete strategies. It declares a method the context uses to execute a
 * strategy.
 */

class Strategy
{
public:
    virtual int execute(int a, int b) = 0;
};

}  // namespace Strategy
