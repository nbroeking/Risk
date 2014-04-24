#ifndef SERVERSOCKET_HPP_
#define SERVERSOCKET_HPP_

#include "os_ss/Socket.hpp"

class ServerSocket {
public:
    static ServerSocket* newServerSocket( short int port ) ;

    void listen( int backlog ) ;
    Socket* accept() ;

private:
    ServerSocket() ;
    int fd ;
};

#endif
