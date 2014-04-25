//
//  CommandHandler.cpp
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/7/14.
//
//

#include "CommandHandler.hpp"

CommandHandler::CommandHandler()
{
    //Constructor
}

CommandHandler::~CommandHandler()
{
    //Destructor
}

Event* CommandHandler::handle(string command)
{
    if( command == "quit")
    {
        return new QuitEvent();
    }
    else if( command == "display")
    {
        return new DisplayEvent();
    }
    else //Attack 5 with 3
    {
        string country1, country2;
        
        if (command.length() < 15)
        {
            return new NullEvent();
        }
        string temp = command.substr(0, 6);
        
        if( temp != "attack")
        {
            return new NullEvent();
        }
        
        int count = 0; //I hope josh doesnt see this part cuz its inefficent and he will be mad
        for( int i = 7; (command[i] <= '9')&&(command[i] >= '0' ); i++ )
        {
            count ++;
        }
        temp = command.substr( 7, count);
        
        if( !(temp.length() > 0))
        {
            return new NullEvent();
        }
        country1 = temp;
        
        //Now we check with
        
        if( command[ 7+count] != ' ')
        {
            return new NullEvent();
        }
        temp = command.substr(7+count+1, 4);
        
        int offset = 7+count+1;
        
        int ncount = 0;
        for( int i = offset+5; (command[i] <= '9')&&(command[i] >= '0' ); i++ )
        {
            ncount ++;
        }
        
        if( command[offset+4] != ' ')
        {
            return new NullEvent();
        }
        
        temp = command.substr( offset + 5, ncount);
        if( !(temp.length() > 0))
        {
            return new NullEvent();
        }
        
        country2 = temp;
        
        string answer;
    
        Event *event = new AttackEvent();
        
        event->setEvent(country1+"/"+country2);
        
        //cout << "Event string = " << event->getEvent() << endl;
        
        return event;
    }
}
