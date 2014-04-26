//File:GameApplication
//Written By: Nicolas Broeking
//Written On: April 4, 2014

//This program class is a application that runs the game side of things.
#include "RiskApplication.hpp"
#include "CLEventDelegate.hpp"
#include "CommandHandler.hpp"
#include "GameHandler.hpp"
#include "Handler.hpp"


#ifndef __GameApplication__
#define __GameApplication__

class GameApplication: public RiskApplication
{
    
private:
    UserEventDelegate *eventDelegate;
    Handler* gameHandler;
    
protected:
    GameApplication();
   ~GameApplication();
    
public:
    int run(string ip);
    //Static member variables
    static RiskApplication* getApplication();
    
};

#endif
