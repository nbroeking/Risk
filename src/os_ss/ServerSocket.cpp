#include "os_ss/ServerSocket.hpp"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 

ServerSocket::ServerSocket(){} ;

ServerSocket* ServerSocket::newServerSocket( short int port ) {
    int listenfd = 0;
    struct sockaddr_in serv_addr ;
    
    listenfd = socket( AF_INET, SOCK_STREAM, 0 ) ;

    if( listenfd < 0 ) 
        return NULL ;

    memset( &serv_addr, 0, sizeof(serv_addr) );

    serv_addr.sin_family = AF_INET ;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY) ;
    serv_addr.sin_port = htons( port ) ;

    if( bind( listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr) ) )
        return NULL ;

    ServerSocket* sock = new ServerSocket() ;
    sock->fd = listenfd ;

    return sock ;
}

void ServerSocket::listen( int backlog ) {
    ::listen( this->fd, backlog ) ;
}

Socket* ServerSocket::accept() {
    int connfd = ::accept( this->fd, NULL, NULL ) ;
    return new Socket( connfd ) ;
}
