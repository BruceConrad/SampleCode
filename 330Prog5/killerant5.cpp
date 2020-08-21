/*
//Bruce Conrad killerant3.cpp
//This is the implementation file for the KillerAnt class.
//Worked with: Kaize Yi for debugging purposes
*/

#include "killerant5.h"

const string KillerAnt::TYPE_STR = "KILLERANT";

const int KillerAnt::NUM_CONST_STATS;
const int KillerAnt::NUM_VAR_STATS;

const int KillerAnt::INIT_CONST_STATS[NUM_CONST_STATS] = {20, 2};
const int KillerAnt::INIT_VAR_STATS[NUM_VAR_STATS] = {20, 7, 2, 2, -1, -1, 5, 10, 2, 6};

KillerAnt::KillerAnt(string name): Bug(INIT_CONST_STATS, INIT_VAR_STATS, name)
{
    
}

string KillerAnt::TypeStr() const
{
    return(TYPE_STR);
}

void KillerAnt::Write(ostream& out) const
{
    out << KillerAnt::TypeStr() << '#';
    Bug::Write(out);
}

bool KillerAnt::IsMyEnemy(const PlayerClass* p) const
{
    if(p == NULL)
    {
        return(false);
    }
    
    const KillerAnt* kA = dynamic_cast<const KillerAnt*>(p);
    
    if(kA)
    {
        return(false);
    }
    else
    {
        return(true);
    }
}

KillerAnt::KillerAnt(): Bug(NULL, NULL, "")
{
    
}

//Clone
KillerAnt* KillerAnt::Clone() const
{
    return(new KillerAnt(*this));
}
