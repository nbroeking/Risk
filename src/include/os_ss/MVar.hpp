#ifndef MVAR_HPP_
#define MVAR_HPP_

/*
 * Author: jrahm
 * created: 2014/04/23
 * MVar.hpp: <description>
 */

#include "os_ss/Mutex.hpp"
#include "os_ss/ScopedLock.hpp"

template <class T>
class MVar {
public:
    MVar( T init ) {
        write(init) ;
    }

    T take() {
        readmutex.lock() ;
        T ret = val;
        writemutex.unlock() ;
        return ret ;
    }

    void write( const T& tmp ) {
        writemutex.lock() ;
        val = tmp ;
        readmutex.unlock() ;
    }

    int tryTake( T& ret, int64_t timeout ) {
        if( ! readmutex.lock( timeout ) ) {
            ret = val ;
            writemutex.unlock() ;
            return 0 ;
        }
        return 1 ;
    }

    int tryWrite( const T& tmp, int64_t timeout ) {
        if( ! writemutex.lock( timeout ) ) {
            val = tmp ;
            readmutex.unlock() ;
            return 0 ;
        }
        return 1;
    }

private:
    T val ;

    Mutex readmutex ;
    Mutex writemutex ;
};

#endif /* MVAR_HPP_ */
