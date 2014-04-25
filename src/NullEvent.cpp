//File: NullEvent.h
//Witten By: Nicolas C. Broeking
//Written on: April 7 2014
//Purpose This file is to encapuslate different types of things that can happen in the game.
#include "NullEvent.hpp"

NullEvent::NullEvent()
{
    type = Event::ENULL;
    event = "";
}
NullEvent::~NullEvent()
{
    
}
Event::Type NullEvent::getType() const
{
    return type;
}