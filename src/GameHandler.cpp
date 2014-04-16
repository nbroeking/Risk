//
//  CommandHandler.cpp
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/7/14.
//
//

#include "GameHandler.hpp"

GameHandler::GameHandler()
{
    //Constructor
}

GameHandler::~GameHandler()
{
    //Destructor
}

bool GameHandler::handle(Event * event)
{
    switch (event->getType())
    {
        case Event::DISPLAY:
            //DIsplay stuff
            cout << "Printing the Game \n";
            break;
            
        default:
            //Send it to Josh
            break;
    }
    return true;
}
