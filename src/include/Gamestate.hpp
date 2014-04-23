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
    
<<<<<<< HEAD
    inline int* getCountries()const {return countries;}
    inline int* getOwners()const {return owners;}
    inline int getNumCountries()const{return numCountries;}
=======
    const int* getCountries()const {return countries;}
    const int* getOwners()const {return owners;}
    const int getNumCountries()const{return numCountries;}
>>>>>>> 712f849840ac832757fe017f34532d15d4be289b
    
    void setCountries( int* countriest, int numCountriest);
    void setOwners( int* ownerst, int numCountriest);
    void setNumCountries( int numCountriest);
};
#endif /* defined(____Gamestate__) */
