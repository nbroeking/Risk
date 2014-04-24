//
//  EventMarshlingStrategy.h
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/22/14.
//
//

/* String Type
 
 "<type> <event>" */

#ifndef ____EventMarshlingStrategy__
#define ____EventMarshlingStrategy__

#include <iostream>
#include "Event.hpp"
#include "os_ss/MarshallingStrategy.hpp"

class EventMarshallingStrategy:public MarshallingStrategy<Event>
{
private:
    static EventMarshallingStrategy* inst ;
public:
    int read( const unsigned char* io, size_t len, Event*& into);
    size_t bytesNeeded( const Event& val);
    int write(unsigned char* out, size_t len, const Event& val);
    
    inline static EventMarshallingStrategy& instance() { 
        if( ! inst ) inst = new EventMarshallingStrategy() ;
        return *inst ;
    }
};

#endif /* defined(____EventMarshlingStrategy__) */
