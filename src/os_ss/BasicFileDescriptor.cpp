#include "os_ss/BasicFileDescriptor.hpp"

#include <unistd.h>

BasicFileDescriptor::BasicFileDescriptor( int fd ) {
    this->fd = fd ;
}

ssize_t BasicFileDescriptor::read( unsigned char* arr, size_t len ) {
    return ::read( this->fd, arr, len ) ;
}

void BasicFileDescriptor::write( const unsigned char* arr, size_t len ) {
    ::write( this->fd, arr, len ) ;
}
