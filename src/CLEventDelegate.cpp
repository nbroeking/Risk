//
//  CLEventDelegate.cpp
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/7/14.
//
//

#include "CLEventDelegate.hpp"
using namespace std;
CLEventDelegate::CLEventDelegate()
{
    handler = new CommandHandler();
}
CLEventDelegate::~CLEventDelegate()
{
    delete handler;
}
Event* CLEventDelegate::getCommand()
{
    //get the command
    string instruction;
    cout << "Instruction: ";
    
    cout.flush();
    
    getline(cin, instruction);
    
    cout << endl;
    
    return handler->handle(instruction);
    
}
