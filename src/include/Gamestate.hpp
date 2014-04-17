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
};
#endif /* defined(____Gamestate__) */
