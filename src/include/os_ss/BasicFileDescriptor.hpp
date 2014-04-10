#ifndef BASICFILEDESCRIPTOR_HPP_
#define BASICFILEDESCRIPTOR_HPP_

/*
 * Author: jrahm
 * created: 2014/04/09
 * BasicFileDescriptor.hpp: <description>
 */

#include <cstdlib>
#include "IO.hpp"

class BasicFileDescriptor : public IO {
public:
    BasicFileDescriptor( int fd ) ;
    void read( unsigned char* arr, size_t len ) ;
    void write( const unsigned char* arr, size_t len ) ;
private:
    int fd ;
} ;

#endif /* BASICFILEDESCRIPTOR_HPP_ */
