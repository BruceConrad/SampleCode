/*
//Bruce Conrad explorer4.cpp
//This is the implementation file for the Explorer Class.
//Worked with: Kaize Yi for debugging purposes
*/

#include "explorer5.h"

const string Explorer::TYPE_STR = "EXPLORER";

const int Explorer::NUM_CONST_STATS;
const int Explorer::NUM_VAR_STATS;

const int Explorer::INIT_CONST_STATS[NUM_CONST_STATS] = {42, 8};
const int Explorer::INIT_VAR_STATS[NUM_VAR_STATS] = 
{42, 7, 8, 8, -1, -1, 6, 0, 1, 6};

//Constructors
Explorer::Explorer():Human(NULL, NULL, "")
{
    
}

Explorer::Explorer(string name):Human(INIT_CONST_STATS, INIT_VAR_STATS, name)
{
    
}

//Destructor
Explorer::~Explorer()
{
    
}

//Observers
string Explorer::TypeStr() const
{
    return(TYPE_STR);
}

//Output
void Explorer::Write(ostream& out) const
{
    out << Explorer::TypeStr() << '#';
    Human::Write(out);
}

//Clone
Explorer* Explorer::Clone() const
{
    return(new Explorer(*this));
}

//Overloaded Assignment
const Explorer& Explorer::operator=(const Explorer& e)
{
    Human::operator=(e);
}
