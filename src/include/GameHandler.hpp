//
//  GameHandler.h
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/7/14.
//
//

#ifndef ____GameHandler__
#define ____GameHandler__

#include <iostream>
#include <string>
#include "Handler.hpp"
#include "QuitEvent.hpp"
#include "AttackEvent.hpp"
#include "Gamestate.hpp"
#include "ServerProxy.hpp"
#include "Validator.hpp"

#include "os_ss/Mutex.hpp"
#include "os_ss/ScopedLock.hpp"
#include "os_ss/Condition.hpp"
#include "os_ss/CloseHandler.hpp"

using namespace std;

class GameHandler :public Handler , public GenericObserver<Event>, public GenericObserver<Gamestate>, CloseHandler
{

private:
    Gamestate *state;
    ServerProxy *server;
    
    Validator *validator;
    Mutex gameLock;
    Condition wait;
    
    bool turn;
    bool shouldDie;
    bool didWin;
    
    int player;
public:
    GameHandler();
    ~GameHandler();
    
    bool handle(Event * event);
    
    int init(string);
    
    void onEvent(Event&);
    void onEvent(Gamestate&);
    void onClose();
};
#endif /* defined(____CommandHandler__) */
