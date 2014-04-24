#ifndef SERVERPROXY_HPP_
#define SERVERPROXY_HPP_

/*
 * Author: jrahm
 * created: 2014/04/23
 * ServerProxy.hpp: <description>
 */

#include "os_ss/ServerSocket.hpp"
#include "os_ss/Socket.hpp"
#include "os_ss/NotificationPool.hpp"
#include "os_ss/GenericNotificationPool.hpp"
#include "os_ss/MarshallingStrategy.hpp"

#include "Gamestate.hpp"
#include "Event.hpp"

class ServerProxy {
public:

ServerProxy( MarshallingStrategy<Event>*&, MarshallingStrategy<Gamestate>*& );
ServerProxy();

/*
 * Connect the server proxy to the server
 */
int connect( const std::string& host, short port ) ;

/*
 * Send an event from the server
 */
void sendEvent( Event& evt );

inline void addGameStateObserver( GenericObserver<Gamestate>* observer ) {
    m_gamestate_notifier->subscribe( observer ) ;
}

inline void addEventObserver( GenericObserver<Event>* observer ) {
    m_event_notifier->subscribe( observer ) ;
}

private:
void setup(MarshallingStrategy<Event>*&, MarshallingStrategy<Gamestate>*&) ;

bool connected ;
Socket* m_socket ;

NotificationPool* m_notification_pool ;

GenericNotificationPool<Event>* m_event_notifier ; 
GenericNotificationPool<Gamestate>* m_gamestate_notifier ;

MarshallingStrategy<Event>* m_event_marshalling_strategy ;
MarshallingStrategy<Gamestate>* m_gamestate_marshalling_strategy ;
RawMarshallingStrategy* m_raw_marshalling_strategy ;
} ;

#endif /* SERVERPROXY_HPP_ */
