/*
//Bruce Conrad spider3.cpp
//This is the implementation file for the Spider class.
//Worked with: Kaize Yi for debugging purposes
*/

#include "spider5.h"

const string Spider::TYPE_STR = "SPIDER";

const int Spider::NUM_CONST_STATS;
const int Spider::NUM_VAR_STATS;

const int Spider::INIT_CONST_STATS[NUM_CONST_STATS] = {50, 15};
const int Spider::INIT_VAR_STATS[NUM_VAR_STATS] = {50, 8, 15, 15, -1, -1, 11, 7, 2, 6};

Spider::Spider(string name): Bug(INIT_CONST_STATS, INIT_VAR_STATS, name)
{
    
}

string Spider::TypeStr() const
{
    return(TYPE_STR);
}

void Spider::Write(ostream& out) const
{
    out << Spider::TypeStr() << '#';
    Bug::Write(out);
}

bool Spider::IsMyEnemy(const PlayerClass* p) const
{
    if(p == NULL)
    {
        return(false);
    }
    
    const Spider* s = dynamic_cast<const Spider*>(p);
    
    if(s)
    {
        return(false);
    }
    else
    {
        return(true);
    }
}

Spider::Spider(): Bug(NULL, NULL, "")
{
    
}

//Clone
Spider* Spider::Clone() const
{
    return(new Spider(*this));
}
