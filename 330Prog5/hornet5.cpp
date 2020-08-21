/*
//Bruce Conrad hornet3.cpp
//This is the implementation file for the Hornet class.
//Worked with: Kaize Yi for debugging purposes
*/

#include "hornet5.h"

const string Hornet::TYPE_STR = "HORNET";

const int Hornet::NUM_CONST_STATS;
const int Hornet::NUM_VAR_STATS;

const int Hornet::INIT_CONST_STATS[NUM_CONST_STATS] = {60, 8};
const int Hornet::INIT_VAR_STATS[NUM_VAR_STATS] = {60, 9, 8, 8, -1, -1, 10, 8, 3, 6};


Hornet::Hornet(string name): Bug(INIT_CONST_STATS, INIT_VAR_STATS, name)
{
    
}

string Hornet::TypeStr() const
{
    return(TYPE_STR);
}

void Hornet::Write(ostream& out) const
{
    out << Hornet::TypeStr() << '#';
    Bug::Write(out);
}

bool Hornet::IsMyEnemy(const PlayerClass* p) const
{
    if(p == NULL)
    {
        return(false);
    }
    
    const Hornet* h = dynamic_cast<const Hornet*>(p);
    
    if(h)
    {
        return(false);
    }
    else
    {
        return(true);
    }
}

Hornet::Hornet(): Bug(NULL, NULL, "")
{
    
}

//Clone
Hornet* Hornet::Clone() const
{
    return(new Hornet(*this));
}
