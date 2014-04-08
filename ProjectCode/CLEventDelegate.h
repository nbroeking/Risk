//
//  CLEventDelegate.h
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/7/14.
//
//

#ifndef ____CLEventDelegate__
#define ____CLEventDelegate__

#include <iostream>
#include "UserEventDelegate.h"
#include "Event.h"
#include "

class CLEventDelegate:(public) UserEventDelegate {
    
private:
    CommandHandler *handler;
protected:
    
public:
    
    CLEventDelegate();
    ~CLEventDelegate();
    
    Event getCommand();
    void displayGameState();
    
};
#endif /* defined(____CLEventDelegate__) */
