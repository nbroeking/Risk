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
    
    player = -1;
    turn = false;
    shouldDie = false;
    server = new ServerProxy();
    
    server->addGameStateObserver(this);
    server->addEventObserver(this);
    
    validator= new Validator();
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
    delete validator;
}

bool GameHandler::handle(Event * event)
{
    
    if( shouldDie)
    {
        cout << " \nThe game has ended! YOU WIN!" << endl;
        return false;
    }
    //cout << "Before Lock!" << endl;
    ScopedLock temp(gameLock);
    //cout << "\n after lock" << endl;
    switch (event->getType())
    {
        case Event::DISPLAY:
            //DIsplay stuff
            state->display();
            break;
            
        default:
            
            if( turn )
            {
                //validate
                if(validator->validate(*state, *event, player))
                {
                    server->sendEvent( * event );
                    turn = false;
                }
                else
                {
                    cerr << "\nThat is not a valid move! \n" << endl;
                }
            }
            else
            {
                cout << "\nIt's not your turn!\n" << endl;
            }
            
            
            //Wait for new Gamestate
            break;
    }
    return true;
}
int GameHandler::init(string ip)
{
    ScopedLock lock(gameLock);
    cout << "\nAttempting to join a game!!!\n";
    
    if(server->connect(ip, 5432) != 0)
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
    cerr << "Trying to handle Event" << endl;
    ScopedLock _scopedLock(gameLock);
    
    cerr << "Starting event lock " << endl;
    PongEvent pong ;
    
    string temp;
    string valid;
    
    switch( eventt.getType() )
    {
    case Event::MESSAGE:
        printf("Message from server: %s\n", eventt.getContent().c_str() ) ;
            temp = eventt.getContent().c_str();
            if( temp.length() < 10)
            {
                valid = temp.substr(0,7);
                if( valid == "Player:")
                {
                    valid = temp.substr(7, 1);
#ifdef __linux__
                    player = atoi( valid.c_str() );
#else
                    player = stoi(valid);
#endif
                }
                else if( valid == "youturn" )
                {
                    turn = true;
                }
                else
                {
                    //Party time
                }
            }
            //cout << "you are player: " << player << endl;
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
    cerr << "Ending event lock " << endl;
}
void GameHandler::onEvent(Gamestate& statet)
{
    cerr << "Trying to handle Gamestate" << endl;
    //cout << "Locking the mutex on gamestate " << endl;
    ScopedLock temp(gameLock);
    if(state == NULL)
    {
        delete state;
    }
    
    state = new Gamestate(statet);
    
    wait.signal();
    cerr << "Ending Lock" << endl;
}
void GameHandler::onClose()
{
    shouldDie = true;
}
