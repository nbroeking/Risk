#ifndef GENERICOBSERVER_HPP_
#define GENERICOBSERVER_HPP_

/*
 * Author: jrahm
 * created: 2014/04/09
 * GenericObserver.hpp: <description>
 */

template <class T>
class GenericObserver {
public:
    virtual void onEvent( T& ) = 0;
};

#endif /* GENERICOBSERVER_HPP_ */
