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
    ~Gamestate();
    void display();
    
    inline int* getCountries()const {return countries;}
    inline int* getOwners()const {return owners;}
    inline int getNumCountries()const{return numCountries;}
    
    void setCountries( int* countriest, int numCountriest);
    void setOwners( int* ownerst, int numCountriest);
    void setNumCountries( int numCountriest);
};
#endif /* defined(____Gamestate__) */
