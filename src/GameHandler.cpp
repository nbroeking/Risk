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
    
    server = new ServerProxy();
}

GameHandler::~GameHandler()
{
    //Destructor
    delete state;
    delete server;
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
int GameHandler::init()
{
    cout << "\nAttempting to join a game!!!\n";
    
    
    
}
