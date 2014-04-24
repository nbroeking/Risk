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
    
    server->addGameStateObserver(this);
    server->addEventObserver(this);
}

GameHandler::~GameHandler()
{
    //Destructor
    delete state;
    delete server;
}

bool GameHandler::handle(Event * event)
{
    ScopedLock temp(gameLock);
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
    gameLock.lock();
    cout << "\nAttempting to join a game!!!\n";
    
    if(server->connect("127.0.0.1", 5432) != 0)
    {
        cout << "\n Unable to connect to a game!\n";
        return -1;
    }
    //Wait for gamestate
    wait.wait( gameLock, 20000);
    
    if( state == NULL)
    {
        cout <<"\n Unable to connect to a game!\n";
        return -1;
    }
    return 0;
    
}
void GameHandler::onEvent(Event& eventt)
{
    ScopedLock temp(gameLock);
    
    eventt.getType();
}
void GameHandler::onEvent(Gamestate& statet)
{
    ScopedLock temp(gameLock);
    if(state == NULL)
    {
        delete state;
    }
    
    state = &statet;
    wait.signal();
}
