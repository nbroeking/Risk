//File: Event.h
//Witten By: Nicolas C. Broeking
//Written on: April 7 2014
//Purpose This file is to encapuslate different types of things that can happen in the game.

#ifndef __QuitEvent__
#define __QuitEvent__

#include "Event.hpp"
#include <strings.h>
#include <iostream>

using namespace std;

class QuitEvent:public Event
{
private:

protected:
 
public:
	QuitEvent();
    ~QuitEvent();
    
    Event::Type getType() const;

};

#endif // __Event__
