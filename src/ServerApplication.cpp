#include "ServerApplication.hpp"

#include "os_ss/GenericObserver.hpp"
#include "os_ss/NotificationPool.hpp"
#include "os_ss/GenericNotificationPool.hpp"
#include "os_ss/BasicRawMarshallingStrategy.hpp"
#include "os_ss/LogScope.hpp"

#include "EventMarshallingStrategy.hpp"
#include "PingEvent.hpp"

#include "Debug.hpp"

#include <cstdio>
#include <utility>

void ServerApplication::onEvent( const int& key, Event& evt ) {
    LogScope __ls("onEvent" ) ;
    pair<int,Event*> tmp = make_pair(key,evt.clone()) ;
    m_event_queue.push( tmp ) ;
}

void ServerApplication::acceptConnections() {
    LogScope __ls("acceptConnections" ) ;
    int i = 0 ;
    while( true ) {
        ClientProxy<int>* tmp = acceptConnection(i++) ;
        m_accept_queue.push(tmp) ;
    }
}

ClientProxy<int>* ServerApplication::acceptConnection( int key ) {
    ClientProxy<int>* ret = new ClientProxy<int> ( server->accept(), key ) ;
    ret->addKeyedObserver( * this ) ;
    return ret ;
}

int ServerApplication::run() {
    LogScope __ls("run" ) ;
    server = ServerSocket::newServerSocket( 5432 ) ;
    if( ! server ) {
        perror("Unable to bind to port") ;
        return 1 ;
    }
    server->listen( 5 ) ;

    lprintf("Starting accept thread\n") ;
    Thread* acceptThread = threadGo( this, &ServerApplication::acceptConnections ) ;

    recur_function rec = &ServerApplication::wait_connect1 ;
    while( rec.val != NULL ) {
        rec = (this->*rec.val)();
    }

    acceptThread->join() ;
    return 0 ;
}

ServerApplication::recur_function ServerApplication::wait_connect1() {
    LogScope __ls("wait_connect1" ) ;
    player1 = m_accept_queue.front() ;
    m_accept_queue.pop() ;
    player1->message("Player:1") ;
    return &ServerApplication::wait_connect2 ;
}

ServerApplication::recur_function ServerApplication::wait_connect2() {
    LogScope __ls("wait_connect2" ) ;
    ClientProxy<int>* null = NULL ;
    player2 = m_accept_queue.front_default( null, 5000 ) ;
    player2->message("Player:2") ;
    if( player2 == NULL ) {
        lprintf("No connection in 5 seconds, sending ping to player 1.\n") ;
        return &ServerApplication::send_ping ;
    }
    lprintf("Player 2 has connected.\n") ;
    return &ServerApplication::established ;
}

ServerApplication::recur_function ServerApplication::send_ping() {
    LogScope __ls("send_ping") ;
    PingEvent ping ;
    pair<int,Event*> nullevt = make_pair(0,(Event*)NULL);
    pair<int,Event*> evt = make_pair(0,(Event*)NULL);

    if( player1 ) {
        lprintf("Sending ping to player 1 as a keep alive\n") ;
        if( player1->postEvent( ping ) < 0) {
            lprintf("Post event failed. Player 1 is gone.\n") ;
            delete player1 ;
            player1 = NULL ;
            return &ServerApplication::wait_connect1 ;
        }
    } else {
        // The impossible?
        lprintf("The impossible seems to have happened! The first client is NULL.\n") ;
        return &ServerApplication::wait_connect1 ;
    }

    do {
        if( evt.second ) {
            lprintf("Unsolicited event type: %d from player %d\n",
                evt.second->getType(), evt.first ) ;
            delete evt.second ;
        }
        evt = m_event_queue.front_default( nullevt, 5000 ) ;
        if( ! evt.second ) {
            lprintf("Connection to player 1 was lost!\n") ;
            player1->close() ;
            delete player1 ;
            player1 = NULL ;
            return &ServerApplication::wait_connect1 ;
        } 
        m_event_queue.pop() ;
        printf("Recieved event from player %d. Type %d. Content: %s\n",
            evt.first, evt.second->getType(), evt.second->getContent().c_str() ) ;
    } while ( evt.second->getType() != Event::PONG ) ;

    lprintf("Pong from player 1 received.\n") ;
    return &ServerApplication::wait_connect2 ;
}

ServerApplication::recur_function ServerApplication::established() {
    LogScope __ls("established") ;
    lprintf("Connection Established!\n") ;

    pair<int,Event*> evt ;

    lprintf("Posting gamestates.\n") ;
    Gamestate gs;
    player1->postGamestate(gs) ;
    player2->postGamestate(gs) ;

    return &ServerApplication::player1Turn ;
}

ServerApplication::recur_function ServerApplication::player1Turn() {
    LogScope __ls("player1Turn");
    player1->message("youturn");
    // pair<int,Event*> evt = make_pair( 0, NULL ) ;
    return NULL ;
}
