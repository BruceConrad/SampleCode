/*
//Bruce Conrad spider3.h
//This is the header file for the Spider class.
//Worked with: Kaize Yi for debugging purposes
*/

#ifndef SPIDER5_H
#define SPIDER5_H

#include "bug5.h"

class Spider: public Bug
{
    public:
        //Class constant
        static const string TYPE_STR;
        
        //Constructor
        Spider(string name);
        
        //Observers
        string TypeStr() const;
        bool IsMyEnemy(const PlayerClass* p) const;
        
        //Output
        void Write(ostream& out) const;
        
        //Clone method
        Spider* Clone() const;
        
    private:
        Spider();
        static const int NUM_CONST_STATS = 2;
        static const int NUM_VAR_STATS = 10;
        static const int INIT_CONST_STATS[NUM_CONST_STATS];
        static const int INIT_VAR_STATS[NUM_VAR_STATS];
};


#endif
