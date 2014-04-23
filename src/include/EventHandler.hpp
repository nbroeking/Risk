//
//  CommandHandler.h
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/7/14.
//
//

#ifndef ____EventHandler__
#define ____EventHandler__

#include <iostream>
#include <string>
#include "Handler.hpp"
#include "QuitEvent.hpp"
#include "AttackEvent.hpp"

class EventHandler :public Handler
{
    
public:
    EventHandler();
    ~EventHandler();
    
    bool handle(Event * event);
    
};
#endif /* defined(____EventHandler__) */
