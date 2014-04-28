//
//  Gamestate.h
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/16/14.
//
//

#ifndef ____Gamestate__
#define ____Gamestate__

#include <iostream>

class Gamestate {

private:
    
    int *countries;
    int *owners;
    int numCountries;
    
public:
    Gamestate();
    Gamestate( const Gamestate& copy ) ;
    ~Gamestate();
    void display(int,bool);
    
    inline int* getCountries()const {return countries;}
    inline int* getOwners()const {return owners;}
    inline int getNumCountries()const{return numCountries;}
    
    void setCountries( int* countriest, int numCountriest);
    void setOwners( int* ownerst, int numCountriest);
    void setNumCountries( int numCountriest);
    
    void setCountry(int index, int value)
    {
        countries[index] = value;
    }
    void setOwner( int index, int value)
    {
        owners[index] = value;
    }
    int getCountry(int index)
    {
        return countries[index];
    }
    int getOwner(int index)
    {
        return owners[index];
    }
};
#endif /* defined(____Gamestate__) */
