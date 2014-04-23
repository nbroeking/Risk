//File: DisplayEvent.cpp
//Witten By: Nicolas C. Broeking
//Written on: April 7 2014
//Purpose This file is to encapuslate different types of things that can happen in the game.
#include "DisplayEvent.hpp"

DisplayEvent::DisplayEvent()
{
    type = Event::DISPLAY;
    event = "display";
}
DisplayEvent::~DisplayEvent()
{
    
}
Event::Type DisplayEvent::getType()
{
    return type;
}