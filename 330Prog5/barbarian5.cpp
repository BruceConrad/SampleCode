/*
//Bruce Conrad barbarian5.cpp
//This is the implementation file for the Barbarian Class.
//Worked with: Kaize Yi for debugging purposes
*/

#include "barbarian5.h"

const string Barbarian::TYPE_STR = "BARBARIAN";

const int Barbarian::NUM_CONST_STATS;
const int Barbarian::NUM_VAR_STATS;

const int Barbarian::INIT_CONST_STATS[NUM_CONST_STATS] = {100, 4};
const int Barbarian::INIT_VAR_STATS[NUM_VAR_STATS] = 
{100, 11, 4, 4, -1, -1, 11, 10, 4, 6};

//Constructors
Barbarian::Barbarian():Human(NULL, NULL, "")
{
    
}

Barbarian::Barbarian(string name):Human(INIT_CONST_STATS, INIT_VAR_STATS, name)
{
    
}

//Destructor
Barbarian::~Barbarian()
{
    
}

//Observers

//Enemies are all other players-- other barbarians too?
bool Barbarian::IsMyEnemy(const PlayerClass* p) const
{
    if(p == NULL)
    {
        return(false);
    }
    
    const Human* h = dynamic_cast<const Human*>(p);
    
    if(h)
    {
        return(false);
    }
    else
    {
        return(true);
    }
}

string Barbarian::TypeStr() const
{
    return(TYPE_STR);
}

//Transformers
bool Barbarian::Heal()
{
    bool returnValue = false;
    const int HEAL = 5;
    if(PlayerClass::IsActive())
    {
        PlayerClass::Invigorate(HEAL);
        returnValue = true;
        PlayerClass::ResetCurrentSpeed();
    }
    
    return(returnValue);
}

//Combat
int Barbarian::HitDamage() const
{
    int damageReceived = 0;
    int rollValue = 0;
    const int damageMultiplier = PlayerClass::WillPower()/2;
    
    if(IsActive())
    {
        if(HasWeapon())
        {
            damageReceived = Human::HitDamage() * damageMultiplier;
        }
        else
        {
            damageReceived = PlayerClass::HitDamage() * damageMultiplier;
        }
    }
    
    return(damageReceived);
}

//Output
void Barbarian::Write(ostream& out) const
{
    out << Barbarian::TypeStr() << '#';
    Human::Write(out);
}

//Clone
Barbarian* Barbarian::Clone() const
{
    return(new Barbarian(*this));
}

//Overloaded Assignment
const Barbarian& Barbarian::operator=(const Barbarian& e)
{
    Human::operator=(e);
}
