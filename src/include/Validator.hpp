#ifndef __Validator__
#define __Validator__

#include "Gamestate.hpp"
#include "AllEvents.hpp"

class Validator
{
    
public:
    bool validate(Gamestate*, Event*, int);
};
#endif