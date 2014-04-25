#ifndef SERVERAPPLICATION_HPP_
#define SERVERAPPLICATION_HPP_

/*
 * Author: jrahm
 * created: 2014/04/23
 * ServerApplication.hpp: <description>
 */

#include "Gamestate.hpp"
#include "Event.hpp"

#include "os_ss/Mutex.hpp"
#include "os_ss/ServerSocket.hpp"
#include "os_ss/Socket.hpp"
#include "os_ss/Thread.hpp"
#include "os_ss/MVar.hpp"
#include "os_ss/BlockingQueue.hpp"
#include "os_ss/KeyedObserver.hpp"
#include "os_ss/KeyedNotifier.hpp"
#include "ClientProxy.hpp"

class ServerApplication : private KeyedObserver<int,Event> {
public:
enum State {
      INITIALIZE
    , WAIT_CONNECT_1
    
} ;

struct recur_function {
recur_function( recur_function (ServerApplication::* tmp)() ) {
    val = tmp ;
}
recur_function (ServerApplication::*val)();
};

int run() ;

/* The state functions
 * These guys return the infinitely recursive
 * type of a function that returns a type of itself.
 */
recur_function wait_connect1() ;
recur_function wait_connect2() ;
recur_function send_ping() ;
recur_function established() ;
recur_function player1Turn() ;

void acceptConnections() ;
private:
typedef pair<int,Event*> EventMessage ;
ClientProxy<int>* acceptConnection( int key ) ;
void onEvent( const int& key, Event& evt ) ;

ServerSocket* server ;
BlockingQueue< ClientProxy<int>* > m_accept_queue ;
BlockingQueue< pair<int,Event*> > m_event_queue ;

ClientProxy<int>* player1 ;
ClientProxy<int>* player2 ;

} ;

#endif /* SERVERAPPLICATION_HPP_ */
