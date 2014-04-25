#ifndef CLIENTPROXY_HPP_
#define CLIENTPROXY_HPP_

/*
 * Author: jrahm
 * created: 2014/04/23
 * ClientProxy.hpp: <description>
 */

#include "Debug.hpp"

#include "os_ss/Socket.hpp"
#include "os_ss/KeyedNotifier.hpp"
#include "AllEvents.hpp"
#include "os_ss/GenericObserver.hpp"
#include "os_ss/NotificationPool.hpp"
#include "os_ss/GenericNotificationPool.hpp"
#include "os_ss/BasicRawMarshallingStrategy.hpp"

#include "EventMarshallingStrategy.hpp"
#include "Gamestate.hpp"
#include "GamestateMarshallingStrategy.hpp"

template <class K>
class ClientProxy : public IO, private CloseHandler {

public:
ClientProxy( Socket* socket, const K& key ) {
    m_pool = new NotificationPool( socket, m_raw_marshalling_strategy = &BasicRawMarshallingStrategy::instance() ) ;
    m_genpool = new GenericNotificationPool<Event>( EventMarshallingStrategy::instance() ) ;
    m_event_notifier = new KeyedNotifier<K,Event>( key ) ;

    m_pool->addCloseHandler( this ) ;
    m_pool->subscribe( m_genpool ) ;

    m_genpool->subscribe( m_event_notifier ) ;
    m_pool->start() ;

    this->key = key ;
    this->m_socket = socket ;
    closed = false ;
}

inline void addKeyedObserver( KeyedObserver<K,Event>& observer ) {
    m_event_notifier->addKeyedObserver( &observer );
}

inline void removeKeyedObserver( KeyedObserver<K,Event>& observer ) {
    m_event_notifier.removeKeyedObserver( observer ) ;
}

inline void write( const unsigned char* chrs, size_t len ) {
    m_socket->write(chrs, len) ;
}

inline ssize_t read( unsigned char* chrs, size_t len ) {
    return m_socket->read( chrs, len );
}

int postEvent( const Event& evt ) {
    if( ! closed ) {
        size_t len ;
        unsigned char* ser = serialize( evt, EventMarshallingStrategy::instance(), len ) ;
        if( ser ) {
            m_raw_marshalling_strategy->write(this, ser, len) ;
            delete[] ser ;
            return 0 ;
        } else {
            lprintf("There was an error serializing the event!\n") ;
            return -1 ;
        }
        lprintf("Impossible!\n") ;
    }
    lprintf("Client is already closed.\n") ;
    return -2 ;
}

int postGamestate( const Gamestate& gs ) {
    if( ! closed ) {
        size_t len ;
        unsigned char* ser = serialize( gs, GamestateMarshallingStrategy::instance(), len ) ;
        if( ser ) {
            m_raw_marshalling_strategy->write( this, ser, len ) ;
            delete[] ser ;
            return 0 ;
        } else {
            return -1 ;
        }
    }
    return -2 ;
}

int message( const string& str ) {
    if( ! closed ) {
        MessageEvent evt( str ) ;
        size_t len ;
        unsigned char* ser = serialize( (Event&)evt, EventMarshallingStrategy::instance(), len ) ;
        if( ser ) {
            m_raw_marshalling_strategy->write( this, ser, len );
            delete[] ser ;
            return 0 ;
        } else {
            return -1 ;
        }
    }
    return -2 ;
}

void onClose() {
    if( ! closed ) {
        closed = true ;
        lprintf("Close handler called.\n") ;
        m_socket->close() ;
        CloseEvent evt ;
    
        /* Fake a close event from the client */
        m_genpool->inject( evt ) ;
        m_pool->cancel() ;
    }
}

void close() {
    onClose() ;
}

~ClientProxy() {
    delete m_pool ;
    delete m_genpool ;
    delete m_event_notifier ;
    delete m_socket ;
}

inline const K& getKey() { return key ; }

private:
    NotificationPool* m_pool ;
    GenericNotificationPool<Event>* m_genpool ;
    KeyedNotifier<K,Event>* m_event_notifier ;
    Socket* m_socket ;
    K key ;
    RawMarshallingStrategy* m_raw_marshalling_strategy ;
    MarshallingStrategy<Gamestate>* m_gamestate_marshalling_strategy ;
    bool closed ;
} ;

#endif /* CLIENTPROXY_HPP_ */
