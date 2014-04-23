#ifndef SERVERAPPLICATION_HPP_
#define SERVERAPPLICATION_HPP_

/*
 * Author: jrahm
 * created: 2014/04/23
 * ServerApplication.hpp: <description>
 */

#include "Gamestate.hpp"

#include "os_ss/Mutex.hpp"

class ServerApplication {
public:
void run() ;

private:
Gamestate m_state ;
Mutex m_mutex ;
} ;

#endif /* SERVERAPPLICATION_HPP_ */
