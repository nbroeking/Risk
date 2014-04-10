#ifndef MARSHALLINGSTRATEGY_HPP_
#define MARSHALLINGSTRATEGY_HPP_

/*
 * Author: jrahm
 * created: 2014/04/09
 * MarshallingStrategy.hpp: <description>
 */

#include "os_ss/IO.hpp"

template<class T>
class MarshallingStrategy {
public:
    /* read a type T from an IO stream
     * return 0 on success, otherwise on error  */
    virtual int read( const unsigned char* io, size_t len, T*& into ) = 0;

    /* The number of bytes needed to marshal the type */
    virtual void bytesNeeded( const T& val ) ;

    /* write a type T to an IO stream */
    virtual void write( unsigned char* out, size_t len, const T& val ) = 0;
};

#endif /* MARSHALLINGSTRATEGY_HPP_ */
