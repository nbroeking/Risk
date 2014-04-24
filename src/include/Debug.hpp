#ifndef DEBUG_HPP_
#define DEBUG_HPP_

/*
 * Author: jrahm
 * created: 2014/04/23
 * Debug.hpp: <description>
 */

#include <cstdio>
#include "os_ss/LogScope.hpp"

#define lprintf(fmt,...) printf(fmt,##__VA_ARGS__) ;

#endif /* DEBUG_HPP_ */
