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
#include "RawMarshallingStrategy.hpp"

#include <vector>

class NotificationPool : public Thread {
public:
    NotificationPool( IO* io, RawMarshallingStrategy* strategy ) ;

    void subscribe( IOObserver* observer ) ;
    void unsubscribe( IOObserver* observer ) ;

    virtual void run() ;
private:
    void fireObserverEvent( unsigned char* ch, size_t len ) ;
    /* the list of observers */
    std::vector<IOObserver*> m_observers ;
    IO* m_io ;
    RawMarshallingStrategy* m_marshal_strategy ;
} ;

#endif /* NOTIFICATIONPOOL_HPP_ */
