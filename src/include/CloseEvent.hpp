#ifndef CLOSEEVENT_HPP_
#define CLOSEEVENT_HPP_

/*
 * Author: jrahm
 * created: 2014/04/24
 * CloseEvent.hpp: <description>
 */

#include "Event.hpp"

class CloseEvent : public Event {
public:
inline CloseEvent() { type = Event::CLOSE ; }
inline CloseEvent* clone() { return new CloseEvent( * this ) ; }
};

#endif /* CLOSEEVENT_HPP_ */
