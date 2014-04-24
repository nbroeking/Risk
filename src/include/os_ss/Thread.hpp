#ifndef THREAD_HPP_
#define THREAD_HPP_

#include <inttypes.h>
#include <pthread.h>

/*
 * Author: jrahm
 * created: 2014/01/29
 * Thread.hpp: <description>
 */

class Thread {
public:
    /*
     * The method which is called when the thread is started.
     */
    virtual void run() = 0;

    /*
     * Starts the thread
     */
    virtual int start( pthread_attr_t* attrs = NULL ) ;

    /*
     * Waits for the thread to exit
     */
    int join( ) ;

    /*
     * Kill the thread
     */
    void cancel( ) ;

    virtual ~Thread() ;

protected:
    pthread_t m_thread ;
} ;

template <class T>
class QuickThread : public Thread {
private:

T* obj ;
void (T::*func)() ;

public:

QuickThread( T* obj, void(T::*func)() ):
    obj( obj ), func( func ) {}

void run() {
    (obj->*func)();
}

};

template<class T>
QuickThread<T>* threadGo( T* val, void (T::*func)() ) {
    QuickThread<T>* ret = new QuickThread<T>( val, func ) ;
    ret->start() ;
    return ret ;
}
#endif /* THREAD_HPP_ */
