#include <cstdlib>
#include "Validator.hpp"
bool Validator::validate(Gamestate* s, Event* evt , int player)
{
    const std::string& str = evt->getContent();
    size_t idx = str.find("/");
    
    //cout << "Code : " << str << endl;
    
    string s1 = str.substr(0, idx);
    string s2 = str.substr(idx+1);
    
    int c1 = atoi(s1.c_str());
    int c2 = atoi(s2.c_str());
    
    //cerr << "Country 1 = " << c1 << endl;
    //cerr << "Country 2 = " << c2 << endl;
    
    if( (c1 < 0)||(c2 < 0)||(c1 >= s->getNumCountries())||(c2 >= s->getNumCountries()) )
    {
        return false;
    }
    if( s->getOwner(c1) == player)
    {
        //scout << "Country " << c1 << " belongs to " << s.getOwner(c1) << " but player = " << player << endl;
        //cout << "1\n";
        return false;
    }
    if( s->getOwner(c2) != player)
    {
        //cout << "2\n";
        return false;
    }
    if( s->getCountry(c2) < 2)
    {
        cerr << "\n You cant attack with 1 troop.";
        return false;
    }
    return true;
}
