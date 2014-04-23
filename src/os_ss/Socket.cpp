#include "os_ss/Socket.hpp"

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 

Socket* Socket::newSocket( std::string& hostname, short port ) {
    struct sockaddr_in serv_addr ;
    int sockfd = socket( AF_INET, SOCK_STREAM, 0 ) ;   
    memset( &serv_addr, 0, sizeof( struct sockaddr_in ) ) ;
    
    serv_addr.sin_family = AF_INET ;
    serv_addr.sin_port = htons( port ) ;

    if( inet_pton(AF_INET, hostname.c_str(), &serv_addr.sin_addr) <= 0 ) {
        return NULL ;
    }

    if( connect( sockfd, (struct sockaddr*)&serv_addr,sizeof(serv_addr)) < 0 ) {
        return NULL ;
    }

    return new Socket( sockfd ) ;
}

Socket::Socket(int raw_fd) : BasicFileDescriptor(raw_fd) {}
