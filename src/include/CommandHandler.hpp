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
#include "Event.hpp"

class CommandHandler
{
    
public:
    CommandHandler();
    ~CommandHandler();
    
   Event* handle(string command);
};
#endif /* defined(____CommandHandler__) */
