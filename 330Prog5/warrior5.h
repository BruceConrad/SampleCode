/*
//Bruce Conrad warrior4.h
//This is the header file for the Warrior Class.
//Worked with: Kaize Yi for debugging purposes
*/

#ifndef WARRIOR5_H
#define WARRIOR5_H

#include "human5.h"

class Warrior: public Human
{
    public:
    
    //Class Instance Constants
    static const string TYPE_STR;
    
    //Constructors/Destructor
    Warrior(string name);
    ~Warrior();
    
    //Observers
    string TypeStr() const;
    
    //Output
    virtual void Write(ostream& out) const;
    
    //Clone method
    Warrior* Clone() const;
    
    //Overloaded assignment
    const Warrior& operator=(const Warrior& w);
    
    private:
    
    //Default Constructor
    Warrior();
    
    //Class Instance Constants
    static const int NUM_CONST_STATS = 2;
    static const int NUM_VAR_STATS = 10;
    
    //Class Instance Data Members
    static const int INIT_CONST_STATS[NUM_CONST_STATS];
    static const int INIT_VAR_STATS[NUM_VAR_STATS];
};

#endif
