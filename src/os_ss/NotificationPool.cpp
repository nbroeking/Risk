#include "os_ss/NotificationPool.hpp"
#include <algorithm>

using namespace std ;

NotificationPool::NotificationPool( IO* io, RawMarshallingStrategy* strategy ) {
    this->m_io = io ;
    this->m_marshal_strategy = strategy ;
}

void NotificationPool::subscribe( IOObserver* a_observer ) {
    this->m_observers.push_back( a_observer ) ;
}

void NotificationPool::unsubscribe( IOObserver* a_observer ) {
    std::remove( m_observers.begin(), m_observers.end(), a_observer ) ;
}

void NotificationPool::run() {
    size_t nbytes ;
    while ( true ) {
        unsigned char* tmp = m_marshal_strategy->read( m_io, &nbytes ) ;
        fireObserverEvent( tmp, nbytes );
        delete[] tmp ;
    }
}

void NotificationPool::fireObserverEvent( unsigned char* ch, size_t len ) {
    for ( vector<IOObserver*>::iterator itr = m_observers.begin() ;
          itr != m_observers.end() ; ++ itr ) (*itr)->onBytesRead( ch, len ) ;
}
