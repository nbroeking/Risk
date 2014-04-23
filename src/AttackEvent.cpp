//File: Event.h
//Witten By: Nicolas C. Broeking
//Written on: April 7 2014
//Purpose This file is to encapuslate different types of things that can happen in the game.
#include "AttackEvent.hpp"

AttackEvent::AttackEvent()
{
    type = Event::ATTACK;
    event = "";
}
AttackEvent::~AttackEvent()
{
    
}
Event::Type AttackEvent::getType() const
{
    return type;
}