//File: Event.h
//Witten By: Nicolas C. Broeking
//Written on: April 7 2014
//Purpose This file is to encapuslate different types of things that can happen in the game.

#ifndef __AttackEvent__
#define __AttackEvent__

#include "Event.hpp"
#include <strings.h>
#include <iostream>

using namespace std;

class AttackEvent: public Event
{
private:

protected:
 
public:
	AttackEvent();
    ~AttackEvent();
    
    Event::Type getType() const;

};

#endif // __Event__
