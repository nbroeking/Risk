#include "os_ss/BasicRawMarshallingStrategy.hpp"

unsigned char* BasicRawMarshallingStrategy::read( IO* io, size_t* len ) {
    union {
        int val ;
        unsigned char bytes[ sizeof(int) ] ;
    };
    ssize_t bytes_read = io->read( bytes, sizeof( int ) ) ;
    if( bytes_read < (int)sizeof( int ) ) {
        return NULL ;
        *len = 0 ;
    }
    val = ntohl( val ) ;
    unsigned char* mlc = new unsigned char[val] ;
    io->read( mlc, val );
    *len = val ;
    return mlc ;
}

void BasicRawMarshallingStrategy::write( IO* io, const unsigned char* ptr, size_t len ) {
    int val = len ;
    io->write( (unsigned char*)&val, sizeof(int) );
    io->write( ptr, len ) ;
}
