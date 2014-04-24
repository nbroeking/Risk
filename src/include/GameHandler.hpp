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

#include "os_ss/Mutex.hpp"
#include "os_ss/ScopedLock.hpp"
#include "os_ss/Condition.hpp"


class GameHandler :public Handler , public GenericObserver<Event>, public GenericObserver<Gamestate>
{

private:
    Gamestate *state;
    ServerProxy *server;
    
    Mutex gameLock;
    Condition wait;
public:
    GameHandler();
    ~GameHandler();
    
    bool handle(Event * event);
    
    int init();
    
    void onEvent(Event&);
    void onEvent(Gamestate&);
    
};
#endif /* defined(____CommandHandler__) */
