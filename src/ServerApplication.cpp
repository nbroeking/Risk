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
    srand( time(NULL) ) ;
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
    player1->message("Player:0") ;
    return &ServerApplication::wait_connect2 ;
}

ServerApplication::recur_function ServerApplication::wait_connect2() {
    LogScope __ls("wait_connect2" ) ;
    ClientProxy<int>* null = NULL ;
    player2 = m_accept_queue.front_default( null, 5000 ) ;
    if( player2 == NULL ) {
        lprintf("No connection in 5 seconds, sending ping to player 1.\n") ;
        return &ServerApplication::send_ping ;
    }
    player2->message("Player:1") ;
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
    player1->postGamestate(m_gs) ;
    player2->postGamestate(m_gs) ;

    return &ServerApplication::player1Turn ;
}

void ServerApplication::playerTurn( ClientProxy<int>* p1, ClientProxy<int>* p2 ) {
    // sleep(1) ;
    LogScope __ls("playerTurn");
    // while( true ) {
    
    sleep(1) ;
    lprintf("Sending youturn!\n") ;
    p1->message("youturn");
    // }
    pair<int,Event*> evt = make_pair( 0, (Event*)NULL ) ;
    evt = m_event_queue.front( ) ;
    m_event_queue.pop( ) ;

    if( evt.second->getType() == Event::ATTACK ) {
        const std::string& str = evt.second->getContent() ;
        size_t idx = str.find("/") ;
        string country1 = str.substr( idx+1 ) ;
        string country2 = str.substr( 0, idx ) ;

        int c1 = atoi( country1.c_str() ) ;
        int c2 = atoi( country2.c_str() ) ;

        int troops1 = m_gs.getCountry( c1 ) ;
        int troops2 = m_gs.getCountry( c2 ) ;

        int min = troops1 - troops2 > troops2 ? troops2 : troops1 - troops2 ;
        int max = min > 1 ? min : 1 ;

        lprintf("Attack between %d (%d) and %d (%d).\n", c1, troops1, c2, troops2) ;
        int gone = rand() % max + 1 ;
        lprintf("%d lost %d troops\n", c2, gone) ;

        int newtroops = troops2 - gone ;
        m_gs.setCountry( c2, newtroops ) ;

        int oldowner = m_gs.getOwner( c2 ) ;
        if( newtroops == 0 ) {
            int tmp ;
            lprintf("Country %d has been conquered!\n", c2) ;
            m_gs.setOwner( c2, m_gs.getOwner( c1 ) ) ;
            m_gs.setCountry( c2, 1 ) ;

            tmp = m_gs.getCountry( c1 ) ;
            lprintf("Setting new troops to %d.\n", tmp) ;
            m_gs.setCountry( c1, tmp ) ;

        }

        bool tmp = true ;
        for( int i = 0 ; i < m_gs.getNumCountries() ; ++ i ) {
            if( m_gs.getOwner( i ) == oldowner &&
                 m_gs.getCountry( i ) > 1 ) {
                    tmp = false ;
                    break ;
                }
        }

        if( tmp ) {
            p2->message("You Lose!") ;
            p1->message("You Win!") ;
        }

        p1->postGamestate( m_gs ) ;
        p2->postGamestate( m_gs ) ;
    }
}

ServerApplication::recur_function ServerApplication::player1Turn() {
    playerTurn( player1, player2 ) ;
    return &ServerApplication::player2Turn ;
}

ServerApplication::recur_function ServerApplication::player2Turn() {
    playerTurn( player2, player1 ) ;
    return &ServerApplication::player1Turn ;
}
