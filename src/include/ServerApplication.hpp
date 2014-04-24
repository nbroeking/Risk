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
#include "os_ss/KeyedObserver.hpp"
#include "os_ss/KeyedNotifier.hpp"

class ServerApplication {
public:
void run() ;

private:
KeyedNotifier<string,Event>* acceptConnection() ;

Gamestate m_state ;
Mutex m_mutex ;

ServerSocket* server ;
KeyedNotifier<string,Event>* player1 ;
KeyedNotifier<string,Event>* player2 ;

MVar< std::pair<string,Event*> >* mvar ;

} ;

#endif /* SERVERAPPLICATION_HPP_ */
