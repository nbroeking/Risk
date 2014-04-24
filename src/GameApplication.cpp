//File:GameApplication.cpp
//Written By: Nicolas Broeking
//Written On: April 4, 2014

//This program class is a application that runs the game side of things.

#include "GameApplication.hpp"
#include <string>
#include <iostream>

using namespace std;

GameApplication::GameApplication()
{
    //Created a new application
    //cout << "Creating a GameApplication\n";
    eventDelegate = new CLEventDelegate();
    gameHandler = new GameHandler();
}
GameApplication::~GameApplication()
{
    //cout <<"Destructing a GameApplication\n";
    //Delete a GameApplication
}

RiskApplication* GameApplication::getApplication()
{
    if( application == NULL )
    {
        application = new GameApplication(); //Create a GameApplication
        
    }
    return application;
}
int GameApplication::run()
{
    //Set up
    int run = 1;
    
    //Initilize
    if( ((GameHandler*)gameHandler)->init() < 0)
    {
        run = 0;
    }
    
    
    while( run )
    {
        //get command
        Event* event = ((CLEventDelegate*)eventDelegate)->getCommand();
        //send move to server
        
        if( event->getType() == Event::QUIT)
        {
            run = 0;
        }
        else
        {
            gameHandler->handle(event);
        }
    }
    
    return 0;
}
