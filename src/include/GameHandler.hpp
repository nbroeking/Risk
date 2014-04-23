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


class GameHandler :public Handler
{

private:
    Gamestate *state;
    ServerProxy *server;
public:
    GameHandler();
    ~GameHandler();
    
    bool handle(Event * event);
    
    int init();
    
};
#endif /* defined(____CommandHandler__) */
