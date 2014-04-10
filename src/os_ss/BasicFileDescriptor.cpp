#include "os_ss/BasicFileDescriptor.hpp"

#include <unistd.h>

BasicFileDescriptor::BasicFileDescriptor( int fd ) {
    this->fd = fd ;
}

void BasicFileDescriptor::read( unsigned char* arr, size_t len ) {
    ::read( this->fd, arr, len ) ;
}

void BasicFileDescriptor::write( const unsigned char* arr, size_t len ) {
    ::write( this->fd, arr, len ) ;
}
