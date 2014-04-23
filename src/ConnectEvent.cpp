//File: Event.h
//Witten By: Nicolas C. Broeking
//Written on: April 7 2014
//Purpose This file is to encapuslate different types of things that can happen in the game.
#include "ConnectEvent.hpp"

ConnectEvent::ConnectEvent()
{
    type = Event::CONNECT;
    event = "";
}
ConnectEvent::~ConnectEvent()
{
    
}
Event::Type ConnectEvent::getType() const
{
    return type;
}