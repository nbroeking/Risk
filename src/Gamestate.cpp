//
//  Gamestate.cpp
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/16/14.
//
//

#include "Gamestate.hpp"
#include <iostream>

using namespace std;
Gamestate::Gamestate()
{
    numCountries = 4;
    countries = new int[numCountries];
    owners = new int[numCountries];
    
    for( int i = 0; i < numCountries; i ++)
    {
        countries[i] = 3;
        owners[i] = i%2;
    }
}
Gamestate::~Gamestate()
{
    delete[] countries;
    delete[] owners;
}
void Gamestate::display()
{
    cout << endl;
    cout << "__Gamestate__\n";
    cout << endl;
    cout << "Player 1: \n";
    for( int i = 0; i < numCountries; i++)
    {
        if( owners[i] == 0)
        {
            cout << "Country " << i << " has " << countries[i] << " troops!" << endl;
        }
    }
    cout << endl;
    cout<< "Player 2: \n";
    for( int i = 0; i < numCountries; i++)
    {
        if( owners[i] == 1)
        {
            cout << "Country " << i << " has " << countries[i] << " troops!" << endl;
        }
    }

    cout << endl;
}
void Gamestate::setCountries( int* countriest, int numCountriest)
{
    if( countries != NULL)
    {
        delete[]countries;
    }
    
    if( numCountries < numCountriest)
    {
        return -1;
    }
    return 0;
}
void setOwners( int* ownerst, int numCountries);
void setNumCountries( int numCountries);