/*
//Bruce Conrad barbarian5.h
//This is the header file for the Barbarian Class.
//Worked with: Kaize Yi for debugging purposes
*/

#ifndef BARBARIAN5_H
#define BARBARIAN5_H

#include "human5.h"

class Barbarian: public Human
{
    public:
    
    //Class Instance Constants
    static const string TYPE_STR;
    
    //Constructors/Destructor
    Barbarian(string name);
    ~Barbarian();
    
    //Observers
    bool IsMyEnemy(const PlayerClass* p) const;
    string TypeStr() const;
    
    //Transformers
    bool Heal();
    
    
    //Combat
    int HitDamage() const;
    
    //Output
    virtual void Write(ostream& out) const;
    
    //Clone method
    virtual Barbarian* Clone() const;
    
    //Overloaded assignment
    const Barbarian& operator=(const Barbarian& e);
    
    
    private:
    //Default Constructor
    Barbarian();
    
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
