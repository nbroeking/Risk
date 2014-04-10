#ifndef DEMARSHALLINGSTRATEGY_HPP_
#define DEMARSHALLINGSTRATEGY_HPP_

/*
 * Author: jrahm
 * created: 2014/04/09
 * DemarshallingStrategy.hpp: <description>
 */

#include "os_ss/IO.hpp"

class RawMarshallingStrategy {
public:
    virtual unsigned char* read( IO* io, size_t* len ) = 0;
    virtual void write( IO* io, const unsigned char* ptr ) = 0;
};

#endif /* DEMARSHALLINGSTRATEGY_HPP_ */
