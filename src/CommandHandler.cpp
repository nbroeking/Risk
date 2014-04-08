//
//  CommandHandler.cpp
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/7/14.
//
//

#include "CommandHandler.hpp"

CommandHandler::CommandHandler() {
    //Constructor
}

CommandHandler::~CommandHandler() {
    //Destructor
}

Event* CommandHandler::handle(string command)
{
    Event* evt = NULL;
    
    if( command == "quit") {
        return evt;
    }
    
    return evt;
}
