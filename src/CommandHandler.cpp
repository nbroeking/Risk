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
    
<<<<<<< HEAD
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
=======
//    if( command == "quit")
//    {
//        return new QuitEvent();
//    }
//    else
//    {
//        return new AttackEvent();
//    }
>>>>>>> 034d98b93b6cc30dba3deab3b3656f925f7af490
}
