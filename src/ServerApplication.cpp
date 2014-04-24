#include "ServerApplication.hpp"

#include "os_ss/GenericObserver.hpp"

#include <cstdio>
#include <utility>

#define lprintf(fmt,...) printf(fmt,##__VA_ARGS__) ;

class ServerReader : public KeyedObserver<string,Event> {
public:
ServerReader( MVar< std::pair<string,Event*> >* mvar ) {
    this->mvar = mvar ;
}

void onEvent( const string& key, Event& evt ) {
    mvar->write( make_pair(key, evt.clone()) ) ;
}

private:
MVar< std::pair<string,Event*> >* mvar ;

};

KeyedNotifier<string,Event>* ServerApplication::acceptConnection() {

}

void ServerApplication::run() {
    lprintf("Starting the server.\n") ;
    server = ServerSocket::newServerSocket( 5432 ) ;

    if( ! server ) {
        lprintf("Unable to create server socket.\n") ;
        return ;
    }

}
