//File: Event.h
//Witten By: Nicolas C. Broeking
//Written on: April 7 2014
//Purpose This file is to encapuslate different types of things that can happen in the game.

#ifndef __NullEvent__
#define __NullEvent__

#include "Event.hpp"
#include <strings.h>
#include <iostream>

using namespace std;

class NullEvent: public Event
{
private:
    
protected:
    
public:
	NullEvent();
    ~NullEvent();
    
    Event::Type getType() const;
    
    inline NullEvent* clone() {
        return new NullEvent( * this ) ;
    }
};

#endif // __Event__
