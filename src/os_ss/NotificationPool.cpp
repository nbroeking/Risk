#include "os_ss/NotificationPool.hpp"
#include <algorithm>

#include "Debug.hpp"

using namespace std ;

NotificationPool::NotificationPool( IO* io, RawMarshallingStrategy* strategy ) {
    this->m_io = io ;
    this->m_marshal_strategy = strategy ;
	this->finish = false ;
	this->m_alloc = NULL ;
}

void NotificationPool::subscribe( IOObserver* a_observer ) {
    this->m_observers.push_back( a_observer ) ;
}

void NotificationPool::unsubscribe( IOObserver* a_observer ) {
    std::remove( m_observers.begin(), m_observers.end(), a_observer ) ;
}

void NotificationPool::run() {
    size_t nbytes = 0;
    while ( ! finish ) {
        m_alloc = m_marshal_strategy->read( m_io, &nbytes ) ;

		if( m_alloc == NULL || nbytes == 0 ) {
			lprintf("0 Bytes read or m_alloc == NULL. Cancel.\n") ;
			fireCloseEvent() ;
			return ;
		}
    	fireObserverEvent( m_alloc, nbytes );
		m_mutex.lock() ;
        	delete[] m_alloc ;
			m_alloc = NULL ;
		m_mutex.unlock() ;
    }
}

void NotificationPool::fireCloseEvent() {
	for ( vector<CloseHandler*>::iterator itr = m_close_handlers.begin() ;
 			itr != m_close_handlers.end() ; ++ itr )
				(*itr)->onClose() ;
}

void NotificationPool::fireObserverEvent( unsigned char* ch, size_t len ) {
    for ( vector<IOObserver*>::iterator itr = m_observers.begin() ;
          itr != m_observers.end() ; ++ itr ) (*itr)->onBytesRead( ch, len ) ;
}

void NotificationPool::cancel() {
	finish = true ;

	m_mutex.lock() ;
	Thread::cancel() ;
	m_mutex.unlock() ;

	if(m_alloc != NULL) {
		delete[] m_alloc ;
		m_alloc = NULL ;
	}

	fireCloseEvent() ;
}

void NotificationPool::addCloseHandler( CloseHandler* handler ) {
	m_close_handlers.push_back( handler ) ;
}

void NotificationPool::removeCloseHandler( CloseHandler* handler ) {
    std::remove( m_close_handlers.begin(), m_close_handlers.end(), handler ) ;
}

NotificationPool::~NotificationPool() {}
