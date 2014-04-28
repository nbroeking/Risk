#ifndef LOGSCOPE_HPP_
#define LOGSCOPE_HPP_

/*
 * Author: jrahm
 * created: 2014/04/23
 * LogScope.hpp: <description>
 */

#include <cstdio>
class LogScope {
public:
LogScope( const char* ctx, FILE* fp = stdout ) {
    this->ctx = ctx ;
    this->fp = fp ;
    //fprintf(this->fp,"[Entering %s]\n", this->ctx) ;
}
~LogScope() {
    //fprintf(this->fp,"[/Leaving %s]\n", this->ctx);
}
private:
const char* ctx ;
FILE* fp ;
};

#endif /* LOGSCOPE_HPP_ */
