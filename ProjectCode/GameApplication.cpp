//File:GameApplication.cpp
//Written By: Nicolas Broeking
//Written On: April 4, 2014

//This program class is a application that runs the game side of things.

#include "GameApplication.h"
#include <iostream>

using namespace std;

GameApplication::GameApplication()
{
    //Created a new application
    cout << "Creating a GameApplication\n";
}
GameApplication::~GameApplication()
{
    cout <<"Destructing a GameApplication\n";
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

/*void GameApplication::cleanUpApplication()
{
    if( application != NULL)
    {
        delete application;
        application = NULL;
    }
}*/
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