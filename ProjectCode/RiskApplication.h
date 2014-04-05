//File: RiskApplication.h
//This class is the abstract class for a RiskApplication. 
//Written By: Nicolas C. Broeking
//Created on April 4, 2014

#ifndef __RiskApplication__
#define __RiskApplication__

class RiskApplication
{
protected:
    RiskApplication *application;
    
    virtual int run() = 0;
    
    virtual RiskApplication() = 0;
    virtual ~RiskApplication() = 0;
    
public:
    virtual int createApplication() = 0;
}
#endif
