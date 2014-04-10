#ifndef IOOBSERVER_HPP_
#define IOOBSERVER_HPP_

/*
 * Author: jrahm
 * created: 2014/04/09
 * IOObserver.hpp: <description>
 */

#include <cstdlib>

class IOObserver {
public:
    virtual void onBytesRead( const unsigned char* bytes, size_t len ) = 0;
};

#endif /* IOOBSERVER_HPP_ */
