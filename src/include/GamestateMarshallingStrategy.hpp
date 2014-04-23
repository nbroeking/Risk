//
//  GamestateMarshlingStrategy.h
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/22/14.
//
//

/* String Type
 
 "<type> <event>" */

#ifndef ____GamestateMarshlingStrategy__
#define ____GamestateMarshlingStrategy__

#include <iostream>
#include "Event.hpp"
#include "Gamestate.hpp"
#include "os_ss/MarshallingStrategy.hpp"

class GamestateMarshallingStrategy:public MarshallingStrategy<Gamestate>
{
private:
    
public:
    int read( const unsigned char* io, size_t len, Gamestate*& into);
    size_t bytesNeeded( const Gamestate& val);
    int write(unsigned char* out, size_t len, const Gamestate& val);
    
};

#endif /* defined(____EventMarshlingStrategy__) */
