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

class GameHandler :public Handler
{

private:
    
    
public:
    GameHandler();
    ~GameHandler();
    
    bool handle(Event * event);
    
};
#endif /* defined(____CommandHandler__) */
