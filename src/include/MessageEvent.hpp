#ifndef MESSAGEEVENT_HPP_
#define MESSAGEEVENT_HPP_

/*
 * Author: jrahm
 * created: 2014/04/23
 * MessageEvent.hpp: <description>
 */

#include "Event.hpp"

class MessageEvent : public Event {
public:
inline MessageEvent( const string& msg ) {
    setEvent( msg ) ;
    type = Event::MESSAGE ;
}

inline MessageEvent() {
    type = Event::MESSAGE ;
}

inline MessageEvent* clone() {
    return new MessageEvent( * this ) ;
}

} ;

#endif /* MESSAGEEVENT_HPP_ */
