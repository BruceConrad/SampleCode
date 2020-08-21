/*
//Bruce Conrad bug3.h
//This is the header file for the BugClass.
//Worked with: for debugging purposes
*/

#ifndef BUG5_H
#define BUG5_H

#include "player5.h"

class Bug: public PlayerClass
{
    public:
        //Output
        void Write(ostream& out) const;
        
        //Observer(s)
        virtual bool IsMyEnemy(const PlayerClass* p) const = 0;
        virtual string TypeStr() const = 0;
        
        //Clone method
        virtual Bug* Clone() const = 0;
        
    protected:
        Bug(const int INIT_CONST_STATS[], const int INIT_VAR_STATS[], string NAME);
        
    private:
        Bug();
};


#endif
