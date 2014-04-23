//
//  CommandHandler.h
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/7/14.
//
//

#ifndef ____CommandHandler__
#define ____CommandHandler__

#include <iostream>
#include <string>
<<<<<<< HEAD
#include "Handler.hpp"
#include "QuitEvent.hpp"
#include "AttackEvent.hpp"
#include "DisplayEvent.hpp"
=======
// #include "Handler.hpp"
// #include "QuitEvent.hpp"
// #include "AttackEvent.hpp"
#include "Event.hpp"
>>>>>>> 034d98b93b6cc30dba3deab3b3656f925f7af490

class CommandHandler
{
    
public:
    CommandHandler();
    ~CommandHandler();
    
    Event* handle(string command);
    
};
#endif /* defined(____CommandHandler__) */
