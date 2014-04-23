#ifndef CONDITION_HPP_
#define CONDITION_HPP_

/*
 * Author: jrahm
 * created: 2014/01/29
 * Condition.hpp: <description>
 */

#include <pthread.h>
#include "os_ss/Time.hpp"
#include "os_ss/Mutex.hpp"

class Condition {
public:
    Condition() ;

    virtual void signal() ;
    virtual bool wait( Mutex& mutex, timeout_t timeout=-1 ) ;

    virtual ~Condition() ;
private:
    pthread_cond_t m_condition ;
} ;

#endif /* CONDITION_HPP_ */
