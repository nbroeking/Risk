#ifndef IO_HPP_
#define IO_HPP_

/*
 * Author: jrahm
 * created: 2014/04/09
 * IO.hpp: <description>
 */

#include <unistd.h>

class IO {
public:
    virtual ssize_t read( unsigned char* arr, size_t len ) = 0;
    virtual void write( const unsigned char* arr, size_t len ) = 0;
};

#endif /* IO_HPP_ */
