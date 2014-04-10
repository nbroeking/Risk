#ifndef SOCKET_HPP_
#define SOCKET_HPP_

/*
 * Author: jrahm
 * created: 2014/04/09
 * Socket.hpp: <description>
 */

#include "BasicFileDescriptor.hpp"

class Socket : public BasicFileDescriptor {
public:
    /* Create a new socket */
    static Socket newSocket() ;
} ;

#endif /* SOCKET_HPP_ */
