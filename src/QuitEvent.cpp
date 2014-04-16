//File: Event.h
//Witten By: Nicolas C. Broeking
//Written on: April 7 2014
//Purpose This file is to encapuslate different types of things that can happen in the game.
#include "QuitEvent.hpp"

QuitEvent::QuitEvent()
{
    type = Event::QUIT;
    event = "";
}
QuitEvent::~QuitEvent()
{
    
}
Event::Type QuitEvent::getType()
{
    return type;
}