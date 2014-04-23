#include <iostream>
#include <cstdio>
#include <cstring>

#include "GameApplication.hpp"

#include "os_ss/Socket.hpp"
#include "os_ss/ServerSocket.hpp"
#include "os_ss/NotificationPool.hpp"
#include "os_ss/BasicRawMarshallingStrategy.hpp"

class PrintIOObserver : public IOObserver {
public:
void onBytesRead( const unsigned char* bytes, size_t len ) {
    if( ! bytes ) return ;
    char* buf = new char[len + 1] ;
    strncpy( buf, (const char*)bytes, len );
    buf[len] = 0;
    printf("Read %d bytes: %s\n", (int)len, buf) ;
    delete[] buf ;
}
};

int main()
{
    printf("Starting server socket\n") ;
    ServerSocket* serv = ServerSocket::newServerSocket( 5432 ) ;

    if( ! serv ) {
        perror( "Failed to create server socket" );
        return 1;
    }

    printf("Listen\n") ;
    serv->listen( 5 ) ;
    printf("Accept\n");
    Socket* sock = serv->accept() ;

    printf("Creating pool\n") ;
    NotificationPool pool(sock, new BasicRawMarshallingStrategy() ) ;
    pool.subscribe( new PrintIOObserver() );

    pool.start() ;
    pool.join() ;
}
