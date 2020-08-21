/*
//Bruce Conrad explorer5.h
//This is the header file for the Explorer Class.
//Worked with: Kaize Yi for debugging purposes
*/

#ifndef EXPLORER5_H
#define EXPLORER5_H

#include "human5.h"

class Explorer: public Human
{
    public:
    
    //Class Instance Constants
    static const string TYPE_STR;
    
    //Constructors/Destructor
    Explorer(string name);
    ~Explorer();
    
    //Observers
    string TypeStr() const;
    
    //Output
    virtual void Write(ostream& out) const;
    
    //Clone method
    virtual Explorer* Clone() const;
    
    //Overloaded assignment
    const Explorer& operator=(const Explorer& e);
    
    
    private:
    //Default Constructor
    Explorer();
    
    //Class Instance Constants
    static const int NUM_CONST_STATS = 2;
    static const int NUM_VAR_STATS = 10;
    
    //Class Instance Data Members
    static const int INIT_CONST_STATS[NUM_CONST_STATS];
    static const int INIT_VAR_STATS[NUM_VAR_STATS];
    //Data Types
    enum StatsType{HEALTH, WILLPOWER, SPEED, MOMENTUM, CUR_ROW, CUR_COL, POWER, DEF_VALUE, NUM_DICE, DIE_FACES, INVALID_STAT};
};

#endif
