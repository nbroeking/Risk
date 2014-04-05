//File:GameApplication.cpp
//Written By: Nicolas Broeking
//Written On: April 4, 2014

//This program class is a application that runs the game side of things.

#include "GameApplication.h"
#include <iostream>

using namespace std;

int GameApplication::createApplication()
{
    if( this->application == NULL )
    {
        application = new GameApplication(); // Create a new application
        
        int result = application->run(); //Run and get the exit code
        
        delete application; //Clean up memory
        
        return result;
    }
}

int GameApplication::run()
{
    //Set up
    int run = 0;
    
    while( run )
    {
        //Run the game
    }
    
    cout << "We ran the game!" << endl;
    return 0;
}