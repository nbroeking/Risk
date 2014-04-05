//File:GameApplication
//Written By: Nicolas Broeking
//Written On: April 4, 2014

//This program class is a application that runs the game side of things.
#include "RiskApplication.h"

#ifndef __GameApplication__
#define __GameApplication__

class GameApplication: public RiskApplication
{
private:
    GameApplication();
    ~GameApplication();
    
protected:
    //int run();
    
public:
    int createApplication();
};

#endif