#include "ServerProxy.hpp"
#include "EventMarshallingStrategy.hpp"
#include "GamestateMarshallingStrategy.hpp"
#include "os_ss/BasicRawMarshallingStrategy.hpp"

ServerProxy::ServerProxy( MarshallingStrategy<Event>*& evt, MarshallingStrategy<Gamestate>*& gs ) {
    this->setup( evt, gs ) ;
}

ServerProxy::ServerProxy() {
    MarshallingStrategy<Event>* m1 = new EventMarshallingStrategy() ;
    MarshallingStrategy<Gamestate>* m2 = new GamestateMarshallingStrategy() ;
    m_raw_marshalling_strategy = &BasicRawMarshallingStrategy::instance();
    this->setup( m1, m2 ) ;
}

void ServerProxy::setup(MarshallingStrategy<Event>*& evt, MarshallingStrategy<Gamestate>*& gs) {
    this->m_event_marshalling_strategy = evt ;
    this->m_gamestate_marshalling_strategy = gs ;

    m_event_notifier = new GenericNotificationPool<Event>( *evt );
    m_gamestate_notifier = new GenericNotificationPool<Gamestate>( *gs );
}

int ServerProxy::connect( const std::string& host, short port ) {
    this->m_socket = Socket::newSocket( host, port ) ;
    if( ! this->m_socket ) return -1 ;
    m_notification_pool = new NotificationPool( this->m_socket, new BasicRawMarshallingStrategy() ) ;
    m_notification_pool->subscribe( m_event_notifier ) ;
    m_notification_pool->subscribe( m_gamestate_notifier ) ;
    m_notification_pool->start() ;
    return 0 ;
}

void ServerProxy::sendEvent( Event& evt ) {
    size_t len ;
    unsigned char* tosend = serialize( evt, *m_event_marshalling_strategy, len ); ;
    m_raw_marshalling_strategy->write( m_socket, tosend, len ) ;
}
void ServerProxy::addCloseObserver( CloseHandler *handle)
{
    m_notification_pool->addCloseHandler(handle);
}
