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
    enum Type {
          QUIT = 0
        , ATTACK = 1
        , DISPLAY = 2
        , CONNECT = 3
        , MESSAGE = 4
        , PING = 5
        , PONG = 6
        , CLOSE = 7
        , ENULL = 8
    };
    
    virtual Type getType() const { return type; };
    
    inline const string& getEvent() const {return event;}
    inline const string& getContent() const { return event ; }
    inline void setEvent(const string& events){ event = events; }

    virtual Event* clone() = 0 ;
private:

protected:

    Type type;
	string event;
};

#endif // __Event__
