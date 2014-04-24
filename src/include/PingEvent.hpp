#ifndef PINGEVENT_HPP_
#define PINGEVENT_HPP_

/*
 * Author: jrahm
 * created: 2014/04/23
 * PingEvent.hpp: <description>
 */

#include "Event.hpp"

class PingEvent : public Event {
public:
inline PingEvent() {
    type = Event::PING ;
}

inline PingEvent* clone() {
    return new PingEvent( * this ) ;
}
} ;

class PongEvent : public Event {
public:
inline PongEvent() {
    type = Event::PONG ;
}

inline PongEvent* clone() {
    return new PongEvent( * this ) ;
}
} ;


#endif /* PINGEVENT_HPP_ */
