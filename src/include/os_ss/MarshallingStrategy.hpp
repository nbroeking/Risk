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
    virtual size_t bytesNeeded( const T& val ) = 0;

    /* write a type T to an IO stream */
    virtual int write( unsigned char* out, size_t len, const T& val ) = 0;
};

template<class T>
inline unsigned char* serialize( const T& val, MarshallingStrategy<T>& strat, size_t& len ) {
    len = strat->bytesNeeded( val ) ;
    unsigned char* ret = new unsigned char[ len ] ;
    if( ! strat->write( ret, len, val ) ) {
        return ret ;
    }
    delete[] ret ;
    len = 0 ;
    return NULL ;
}
#endif /* MARSHALLINGSTRATEGY_HPP_ */
