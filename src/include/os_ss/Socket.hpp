#ifndef SOCKET_HPP_
#define SOCKET_HPP_

/*
 * Author: jrahm
 * created: 2014/04/09
 * Socket.hpp: <description>
 */

#include "BasicFileDescriptor.hpp"

#include <string>

class Socket : public BasicFileDescriptor {
public:
    Socket( int raw_fd ) ;

    /* Create a new socket */
    static Socket* newSocket(std::string& hostname, short port) ;
} ;

#endif /* SOCKET_HPP_ */
