#include <iostream>
#include <cstdio>
#include <cstring>

#include "GameApplication.hpp"
#include "ServerApplication.hpp"

int client_main( int argc, char** argv )
{
    if( argc < 2)
    {
        cerr << "You need to enter an IP Adress"<< endl;
        return 1;
    }
    RiskApplication * app = GameApplication::getApplication();
    int answer = app->run(argv[1]);
    app->cleanUpApplication();
    return answer;
}

int server_main( int argc, char** argv ) {
    (void) argc ;
    (void) argv ;
    ServerApplication server;
    return server.run() ;
}

int main( int argc, char** argv ) {
    int idx = strlen( argv[0] ) ;
    for( ; idx >= 0 ; idx -- ) {
        if( argv[0][idx] == '/' ) break ;
    }
    ++ idx ;

    if( strcmp(argv[0]+idx,"HostRisk") == 0 ) {
        return server_main( argc, argv ) ;
    } else if( strcmp(argv[0]+idx,"PlayRisk") == 0 ) {
        return client_main( argc, argv ) ;
    } else {
        printf("Unknown binary name %s; defaulting to client mode!\n", argv[0]+idx) ;
        return client_main( argc, argv ) ;
    }
}
