#ifndef KEYEDNOTIFIER_HPP_
#define KEYEDNOTIFIER_HPP_

/*
 * Author: jrahm
 * created: 2014/04/23
 * KeyedNotifier.hpp: <description>
 */

#include "os_ss/GenericObserver.hpp"
#include "os_ss/KeyedObserver.hpp"

#include <vector>
#include <algorithm>

template <class K, class T>
class KeyedNotifier : public GenericObserver<T> {
public:
KeyedNotifier( const K& tmp ) : key( tmp ) {}

void onEvent( T& val ) {
    for( typename std::vector< KeyedObserver<K,T>* >::iterator
            itr = observers.begin() ; itr != observers.end() ; ++ itr ) {
        (*itr)->onEvent( key, val ) ;
    }
}

void setKey( const K& key ) {
    this->key = key ;
}

void addKeyedObserver( KeyedObserver<K,T>* observer ) {
    this->observers.push_back( observer ) ;
}

void removeKeyedObserver( KeyedObserver<K,T>* observer ) {
    std::remove( observers.begin(), observers.end(), observer ) ;
}

virtual ~KeyedNotifier() {} ;

private:
std::vector< KeyedObserver<K,T>* > observers ;
K key ;
};

#endif /* KEYEDNOTIFIER_HPP_ */
