#ifndef NOTIFICATIONPOOL_HPP_
#define NOTIFICATIONPOOL_HPP_

/*
 * Author: jrahm
 * created: 2014/04/09
 * NotificationPool.hpp: <description>
 */

#include "IO.hpp"
#include "IOObserver.hpp"
#include "Thread.hpp"
#include "Mutex.hpp"
#include "RawMarshallingStrategy.hpp"
#include "os_ss/CloseHandler.hpp"

#include <vector>

class NotificationPool : public Thread {
public:
    NotificationPool( IO* io, RawMarshallingStrategy* strategy ) ;

    void subscribe( IOObserver* observer ) ;
    void unsubscribe( IOObserver* observer ) ;

    void addCloseHandler( CloseHandler* ) ;
    void removeCloseHandler( CloseHandler* ) ;

    virtual void cancel() ;
    virtual void run() ;
    virtual ~NotificationPool() ;
private:
    void fireObserverEvent( unsigned char* ch, size_t len ) ;
    void fireCloseEvent() ;
    /* the list of observers */
    std::vector<IOObserver*> m_observers ;
    std::vector<CloseHandler*> m_close_handlers ;
    IO* m_io ;

    RawMarshallingStrategy* m_marshal_strategy ;
    Mutex m_mutex ;
    bool finish ;

    unsigned char* m_alloc ;
} ;

#endif /* NOTIFICATIONPOOL_HPP_ */
