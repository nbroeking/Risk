//
//  CommandHandler.cpp
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/7/14.
//
//

#include "CommandHandler.h"

CommandHandler::CommandHandler()
{
    //Constructor
}
CommandHandler::~CommandHandler()
{
    //Destructor
}
CommandHandler::handle(string command)
{
    Event = NULL;
    
    if( strcmp( command, "quit"))
    {
        return  Event;
    }
    
    return Event;
}