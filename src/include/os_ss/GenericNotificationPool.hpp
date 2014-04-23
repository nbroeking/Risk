#ifndef GENERICNOTIFICATIONPOOL_HPP_
#define GENERICNOTIFICATIONPOOL_HPP_

/*
 * Author: jrahm
 * created: 2014/04/09
 * GenericNotificationPool.hpp: <description>
 */

#include <algorithm>
#include <iostream>

#include "IOObserver.hpp"
#include "MarshallingStrategy.hpp"
#include "NotificationPool.hpp"
#include "GenericObserver.hpp"

template <class T>
class GenericNotificationPool : public IOObserver {
public:
    GenericNotificationPool(
        NotificationPool& notification,
        MarshallingStrategy<T>& strat ) {
        m_strat = &strat ;
        notification.subscribe( this ) ;
    }

    GenericNotificationPool(
        MarshallingStrategy<T>& strat) {
        m_strat = &strat ;
    }

    void subscribe( GenericObserver<T>* observer ) {
        m_observers.push_back( observer ) ;
    }

    void unsubscribe( GenericObserver<T>* observer ) {
        std::remove( m_observers.begin(), m_observers.end(), observer ) ;
    }

    void onBytesRead( const unsigned char* bytes, size_t len ) {
        T* into ;
        if( m_strat->read( bytes, len, into )  ) {
            std::cerr << "Unable to marshal type" << std::endl;
        } else {
            for( typename std::vector<GenericObserver<T>*>::iterator itr = m_observers.begin() ;
                 itr != m_observers.end() ; ++ itr ) (*itr)->onEvent( *into ) ;
        }
        delete into ;
    }

private:
    MarshallingStrategy<T>* m_strat ;
    std::vector<GenericObserver<T>*> m_observers ;
}; 

#endif /* GENERICNOTIFICATIONPOOL_HPP_ */
