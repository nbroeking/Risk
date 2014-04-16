//
//  Handler.h
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/7/14.
//
//

#ifndef ____Handler__
#define ____Handler__

#include "Event.hpp"
#include <string>

class Handler
{
    
public:
    virtual ~Handler(){}
    virtual Event* handle(string command){(void)command; return NULL ;}
    virtual bool handle(Event *event){(void)event; return false;}
    
};
//Handler::~Handler(){}
#endif /* defined(___Handler__) */
