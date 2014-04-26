//File: RiskApplication.h
//This class is the abstract class for a RiskApplication. 
//Written By: Nicolas C. Broeking
//Created on April 4, 2014
#ifndef __RiskApplication__
#define __RiskApplication__

#include <string>
using namespace std;

class RiskApplication
{
private:
protected:
    static RiskApplication *application;
    
    RiskApplication();
    virtual ~RiskApplication()=0;
    
public:
    virtual int run(string ip) = 0;
    
    
    //Static class variables
    static RiskApplication* getApplication();
    static void cleanUpApplication();
};
#endif
