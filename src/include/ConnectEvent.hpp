//File: Event.h
//Witten By: Nicolas C. Broeking
//Written on: April 7 2014
//Purpose This file is to encapuslate different types of things that can happen in the game.

#ifndef __ConnectEvent__
#define __ConnectEvent__

#include "Event.hpp"
#include <strings.h>
#include <iostream>

using namespace std;

class ConnectEvent: public Event
{
private:

protected:
 
public:
	ConnectEvent();
    ~ConnectEvent();
    
    Event::Type getType() const;

};

#endif // __Event__
