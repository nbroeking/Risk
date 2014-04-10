//File:GameApplication
//Written By: Nicolas Broeking
//Written On: April 4, 2014

//This program class is a application that runs the game side of things.
#include "RiskApplication.hpp"
#include "CLEventDelegate.hpp"
#include "CommandHandler.hpp"


#ifndef __GameApplication__
#define __GameApplication__

class GameApplication: public RiskApplication
{
    
private:
    UserEventDelegate *eventDelegate;
    
protected:
    GameApplication();
   ~GameApplication();
    
public:
    int run();
    
    //Static member variables
    static RiskApplication* getApplication();
    
};

#endif
