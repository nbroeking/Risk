//
//  CLEventDelegate.cpp
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/7/14.
//
//

#include "CLEventDelegate.h"

CLEventDelegate::CLEventDelegate()
{
    handler = new CommandHandler();
}
CLEventDelegate::~CLEventDelegate()
{
    delete handler;
}
Event CLEventDelegate::getCommand()
{
    //get the command
    string instruction;
    cout << "Instruction: ";
    cin >> instruction;
    cout << "\n";
    
    return handler.handle(instruction);
    
}
