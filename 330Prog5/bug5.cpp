/*
//Bruce Conrad bug3.cpp
//This is the implementation file for the BugClass.
//Worked with: for debugging purposes
*/

#include "bug5.h"

Bug::Bug(): PlayerClass(NULL, NULL, "")
{
    
}

Bug::Bug(const int INIT_CONST_STATS[], const int INIT_VAR_STATS[], string NAME):
PlayerClass(INIT_CONST_STATS, INIT_VAR_STATS, NAME)
{
}

void Bug::Write(ostream& out) const
{
    PlayerClass::Write(out);
}
