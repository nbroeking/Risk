//File: Event.h
//Witten By: Nicolas C. Broeking
//Written on: April 7 2014
//Purpose This file is to encapuslate different types of things that can happen in the game.

#ifndef __Event__
#define __Event__

#include <strings.h>
#include <iostream>

using namespace std;

class Event
{
public:
	virtual ~Event(){};
    enum Type {QUIT = 0, ATTACK = 1, DISPLAY = 2, CONNECT = 3};
    
    virtual Type getType() const = 0;
    
    inline const string& getEvent() const {return event;}
    void setEvent(const string& events){ event = events; }

    Event* clone() { return this; } ;
private:

protected:

    Type type;
	string event;
};

#endif // __Event__
