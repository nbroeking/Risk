//File: Event.h
//Witten By: Nicolas C. Broeking
//Written on: April 7 2014
//Purpose This file is to encapuslate different types of things that can happen in the game.

#ifndef __Event__
#define __Event__

#include <strings.h>
#include <iostream>

using namespace std;

enum { COMMANDEVENT, RISKEVENT };

class Event
{
private:

protected:

	string event;
 
public:

	Event();
	virtual ~Event() = 0;

};

#endif __Event__
