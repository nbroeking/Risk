//
//  CommandHandler.cpp
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/7/14.
//
//

#include "GameHandler.hpp"
#include <cstdio>

#include "PingEvent.hpp"

GameHandler::GameHandler()
{
    state = NULL;
    //Constructor
    
    player = 0;
    turn = false;
    shouldDie = false;
    server = new ServerProxy();
    
    server->addGameStateObserver(this);
    server->addEventObserver(this);
}

GameHandler::~GameHandler()
{
    //Destructor
    if( state != NULL)
    {
        delete state;
        state = NULL;
    }
    delete server;
}

bool GameHandler::handle(Event * event)
{
    if( shouldDie)
    {
        cout << " \nJosh broke the server... Good bye" << endl;
        return false;
    }
    cout << "Before Lock!" << endl;
    ScopedLock temp(gameLock);
    cout << "\n after lock" << endl;
    switch (event->getType())
    {
        case Event::DISPLAY:
            //DIsplay stuff
            state->display();
            break;
            
        default:
            server->sendEvent( * event ) ;
            
            //Wait for new Gamestate
            break;
    }
    return true;
}
int GameHandler::init()
{
    ScopedLock lock(gameLock);
    cout << "\nAttempting to join a game!!!\n";
    
    if(server->connect("10.201.6.121", 5432) != 0)
    {
        cout << "\nUnable to connect to a game!\n";
        return -1;
    }
    //Wait for gamestate
    server->addCloseObserver(this);
    wait.wait( gameLock, 20000);
    
    if( state == NULL)
    {
        cout <<"\nUnable to connect to a game!\n";
        return -1;
    }
    return 0;
    
}
void GameHandler::onEvent(Event& eventt)
{
    ScopedLock temp(gameLock);
    
    PongEvent pong ;
    switch( eventt.getType() ) {
    case Event::MESSAGE:
        printf("Message from server: %s\n", eventt.getContent().c_str() ) ;
        break ;
    case Event::PING:
        printf("Ping from server.\n") ;
        server->sendEvent( pong );
        break ;
    case Event::PONG:
        printf("Pong from server.\n");
        break ;
    default: ;
    }
}
void GameHandler::onEvent(Gamestate& statet)
{
    cout << "Locking the mutex on gamestate " << endl;
    ScopedLock temp(gameLock);
    if(state == NULL)
    {
        delete state;
    }
    
    state = &statet;
    wait.signal();
}
void GameHandler::onClose()
{
    shouldDie = true;
}
