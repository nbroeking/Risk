//
//  EventMarshlingStrategy.cpp
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/22/14.
//
//

#include "EventMarshallingStrategy.hpp"
#include "AttackEvent.hpp"
#include "QuitEvent.hpp"
#include "PingEvent.hpp"
#include "MessageEvent.hpp"
#include "Debug.hpp"

EventMarshallingStrategy* EventMarshallingStrategy::inst = NULL ;

int EventMarshallingStrategy::read(const unsigned char* io, size_t len, Event*& into)
{
    if( len < 3||io[0] != 0x01) {
//        lprintf("Error reading event. Length less than 3.\n") ;
        return -1;
    }

    switch( (Event::Type)io[1] ) {
    case Event::ATTACK:
        into = new AttackEvent() ;
        break ;
    case Event::PING:
        into = new PingEvent() ;
        break ;
    case Event::PONG:
        into = new PongEvent() ;
        break ;
    default:
        into = new MessageEvent() ;
        break ;
    }

    std::string str( (char*)io+3, io[2] );
    into->setEvent( str );
    
    return 0;
}
size_t EventMarshallingStrategy::bytesNeeded( const Event& val)
{
    return 3 + val.getEvent().length();
}
int EventMarshallingStrategy::write(unsigned char* out, size_t len, const Event& val)
{
    if( bytesNeeded(val) < len) {
        return -1; //Not correct
    }
    out[0] = 0x01;
    out[1] = val.getType();
    out[2] = val.getEvent().length();
    for( int i = 0; i < out[2]; i++ )
    {
        out[i+3] = val.getEvent()[i];
    }
    
    return 0;
}
