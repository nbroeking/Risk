//File:GameApplication.cpp
//Written By: Nicolas Broeking
//Written On: April 4, 2014

//This program class is a application that runs the game side of things.

#include "RiskApplication.h"
#include <iostream>

using namespace std;

RiskApplication* RiskApplication::application = NULL;

void RiskApplication::cleanUpApplication()
{
    if( application != NULL) //If application hasn't been deleted yet
    {
        delete application; //Delete the app
        application = NULL; // Set the pointer to NULL
    }
}

RiskApplication* RiskApplication::getApplication()
{
    if( application == NULL) //If the application hasnt been created.
    {
        cout << "You can not create a new RiskApplication!\n";
    }
    return application; // Return the applicatons
}

RiskApplication::RiskApplication()
{
    cout<<"Creating a RiskApplication!\n"; //Default RiskApplication constructor
}

RiskApplication::~RiskApplication()
{
    cout<<"Destructing a RiskApplication!\n"; //Default RiskAppliction destructor
}

int RiskApplication::run()
{
    cout <<"Running a RiskApplication!\n"; //Default RiskApplicaton Run
    return 0;
}