#ifndef KEYEDOBSERVER_HPP_
#define KEYEDOBSERVER_HPP_

/*
 * Author: jrahm
 * created: 2014/04/23
 * KeyedObserver.hpp: <description>
 */

template <class K, class T>
class KeyedObserver {
    virtual void onEvent( const K& key, T& val );
} ;

#endif /* KEYEDOBSERVER_HPP_ */
