//File:GameApplication.cpp
//Written By: Nicolas Broeking
//Written On: April 4, 2014

//This program class is a application that runs the game side of things.

#include "GameApplication.hpp"
#include "Debug.hpp"

#include <string>
#include <iostream>
#include "AllEvents.hpp"

using namespace std;

GameApplication::GameApplication()
{
	LogScope("GameApplication") ;
    //Created a new application
    //cout << "Creating a GameApplication\n";
    eventDelegate = new CLEventDelegate();
	GameHandler* tmp = new GameHandler() ;
	gameHandler = tmp ;
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
int GameApplication::run(string ip)
{
	LogScope("run") ;
    //Set up
    int run = 1;
    
    //Initilize
    if( ((GameHandler*)gameHandler)->init(ip) < 0)
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
        else if( event->getType() == Event::ENULL )
        {
            cout << "\nThat is not a valid command please try again! \n" << endl;
        }
        else
        {
            //Validation first
            cout << "Josh handles it \n";
                if(!gameHandler->handle(event) )
                {
                    run = false;
                    continue;
                }
        }
    }
    
    return 0;
}
