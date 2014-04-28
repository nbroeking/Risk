//
//  Gamestate.cpp
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/16/14.
//
//

#include "Gamestate.hpp"
#include <iostream>

#include <algorithm>

using namespace std;
Gamestate::Gamestate()
{
    numCountries = 4;
    countries = new int[numCountries];
    owners = new int[numCountries];
    
    for( int i = 0; i < numCountries; i ++)
    {
        countries[i] = 2;
        owners[i] = i%2;
    }
}

Gamestate::Gamestate( const Gamestate& copy ) {
	numCountries = copy.numCountries ;
	this->countries = new int[numCountries] ;
	this->owners = new int[numCountries] ;

	for( int i = 0 ; i < numCountries ; ++ i ) {
		this->countries[i] = copy.countries[i] ;
		this->owners[i] = copy.owners[i] ;
	}
}

Gamestate::~Gamestate()
{
    delete[] countries;
    delete[] owners;
}
void Gamestate::display(int player, bool turn)
{
    cout << endl;
    cout << "__Gamestate__\n";
    cout << endl;
    
    if( turn )
    {
        cout << "It is your turn!!" << endl << endl;
    }
    
    if( player == 0)
    {
        cout << "Your team: \n";
    }
    else
    {
        cout << "The bad guys \n";
    }
    for( int i = 0; i < numCountries; i++)
    {
        if( owners[i] == 0)
        {
            cout << "Country " << i << " has " << countries[i] << " troops!" << endl;
        }
    }
    cout << endl;
    
    if( player == 1)
    {
        cout << "Your team: \n";
    }
    else
    {
        cout << "The bad guys \n";
    }
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
    
    if( numCountries != numCountriest)
    {
        return;
    }
    
    countries = new int[numCountries];
    
    for( int i = 0; i < numCountries; i++)
    {
        countries[i] = countriest[i];
    }
    return;
}
void Gamestate::setOwners( int* ownerst, int numCountriest)
{
    if( owners != NULL)
    {
        delete[]owners;
    }
    
    if( numCountries != numCountriest)
    {
        return;
    }
    
    owners = new int[numCountries];
    
    for( int i = 0; i < numCountries; i++)
    {
        owners[i] = ownerst[i];
    }
    return;
}
void Gamestate::setNumCountries( int numCountriest)
{
    numCountries = numCountriest;
}
