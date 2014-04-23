//
//  CommandHandler.cpp
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/7/14.
//
//

#include "CommandHandler.hpp"

CommandHandler::CommandHandler()
{
    //Constructor
}

CommandHandler::~CommandHandler()
{
    //Destructor
}

Event* CommandHandler::handle(string command)
{
    if( command == "quit")
    {
        return new QuitEvent();
    }
    else if( command == "display")
    {
        return new DisplayEvent();
    }
    else
    {
        return new AttackEvent();
    }
}
