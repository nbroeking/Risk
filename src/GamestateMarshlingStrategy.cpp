//
//  EventMarshlingStrategy.cpp
//  
//
//  Created by Nicolas Charles Herbert Broeking on 4/22/14.
//
//

#include "GamestateMarshallingStrategy.hpp"
#include "Gamestate.hpp"

int GamestateMarshallingStrategy::read(const unsigned char* io, size_t len, Gamestate*& into)
{
    if( len <= 2||io[0] != 0x00)
    {
        return -1;
    }
    
    into = new Gamestate();
    
    into->setNumCountries((int)io[1]);
    
    int* temp = new int[(int)io[1]];
    
    int* temp1 = new int[(int)io[1]];
    
    for( int i = 0; i < (int)io[1]; i++)
    {
        temp[i] = (int)io[i+2];
        temp1[i] = (int)io[i+2+(int)io[1]];
    }
        into->setCountries(temp, (int)io[1]);
        into->setOwners(temp1, (int) io[1]);
    
    return 0;
}
size_t GamestateMarshallingStrategy::bytesNeeded( const Gamestate& val)
{
    return 2+ val.getNumCountries()*2;
}
int GamestateMarshallingStrategy::write(unsigned char* out, size_t len, const Gamestate& val)
{

    if( bytesNeeded(val) > len)
    {
        return -1;
    }
    
    out[0] = 0x00;
    out[1] = (char)val.getNumCountries();
    
    for( int i = 0; i < val.getNumCountries(); i++)
    {
        out[i+2] = (char)val.getCountries()[i];
    }
    for( int i = 0; i < val.getNumCountries(); i++)
    {
        out[i+2+val.getNumCountries()] = (char)val.getOwners()[i];
    }
    return bytesNeeded(val);
}
