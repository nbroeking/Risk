//File: Event.h
//Witten By: Nicolas C. Broeking
//Written on: April 7 2014
//Purpose This file is to encapuslate different types of things that can happen in the game.

#ifndef __DisplayEvent__
#define __DisplayEvent__

#include "Event.hpp"
#include <strings.h>
#include <iostream>

using namespace std;

class DisplayEvent: public Event
{
private:

protected:
 
public:
	DisplayEvent();
    ~DisplayEvent();
    
    Event::Type getType();

};

#endif // __Event__
