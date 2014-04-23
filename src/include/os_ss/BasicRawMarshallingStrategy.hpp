#include "os_ss/RawMarshallingStrategy.hpp"
#include <arpa/inet.h>

class BasicRawMarshallingStrategy : public RawMarshallingStrategy {
public:

virtual unsigned char* read( IO* io, size_t* len ) ;

virtual void write( IO* io, const unsigned char* ptr, size_t len ) ;
    
};
