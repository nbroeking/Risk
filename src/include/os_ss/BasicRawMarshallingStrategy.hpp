#ifndef BASICRAWMARSHALLINGSTRATEGY_HPP_
#define BASICRAWMARSHALLINGSTRATEGY_HPP_

#include "os_ss/RawMarshallingStrategy.hpp"
#include <arpa/inet.h>

class BasicRawMarshallingStrategy : public RawMarshallingStrategy {
private:
    static BasicRawMarshallingStrategy* inst ;
public:
virtual unsigned char* read( IO* io, size_t* len ) ;
virtual void write( IO* io, const unsigned char* ptr, size_t len ) ;
inline static BasicRawMarshallingStrategy& instance() {
    if( ! inst ) inst = new BasicRawMarshallingStrategy() ;
    return * inst ;
}

};

#endif
