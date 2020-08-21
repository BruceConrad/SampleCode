/*
//Bruce Conrad warrior4.cpp
//This is the implementation file for the Warrior Class.
//Worked with: Kaize Yi for debugging purposes
*/

#include "warrior5.h"

const string Warrior::TYPE_STR = "WARRIOR";

const int Warrior::NUM_CONST_STATS;
const int Warrior::NUM_VAR_STATS;

const int Warrior::INIT_CONST_STATS[NUM_CONST_STATS] = {81, 5};
const int Warrior::INIT_VAR_STATS[NUM_VAR_STATS] = 
{81, 9, 5, 5, -1, -1, 9, 8, 3, 6};

//Constructors
Warrior::Warrior():Human(NULL, NULL, "")
{
    
}

Warrior::Warrior(string name):Human(INIT_CONST_STATS, INIT_VAR_STATS, name)
{
    
}

//Destructor
Warrior::~Warrior()
{
    
}

//Observers
string Warrior::TypeStr() const
{
    return(TYPE_STR);
}

//Output
void Warrior::Write(ostream& out) const
{
    out << Warrior::TypeStr() << '#';
    Human::Write(out);
}


//Clone
Warrior* Warrior::Clone() const
{
    return(new Warrior(*this));
}

//Overloaded assignment
const Warrior& Warrior::operator=(const Warrior& w)
{
    Human::operator=(w);
}
