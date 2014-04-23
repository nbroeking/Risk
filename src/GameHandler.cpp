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
    state = new Gamestate();
    //Constructor
}

GameHandler::~GameHandler()
{
    //Destructor
    delete state;
}

bool GameHandler::handle(Event * event)
{
    switch (event->getType())
    {
        case Event::DISPLAY:
            //DIsplay stuff
            state->display();
            break;
            
        default:
            //Send it to Josh
            break;
    }
    return true;
}
