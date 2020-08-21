/*
//Bruce Conrad player4.cpp
//This is the implementation file of the PlayerClass.
//Worked with: Kaize Yi for debugging purposes
*/



#include "gamespace.h"
#include "dice.h"
#include "player5.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;
using namespace GameSpace;


//Class Constants
	
//Default base constants
const int PlayerClass::DEAD = 0;
const GameSpace::DirType PlayerClass::DEFAULT_DIRECTION = NORTH;
const int PlayerClass::DEFAULT_ROW = -1;
const int PlayerClass::DEFAULT_COL = -1;
const int PlayerClass::NUM_STATS;
const int PlayerClass::IMP_AND_CRIT_ROWS;
const int PlayerClass::IMP_AND_CRIT_COLS;
const int PlayerClass::k = 12;
const int PlayerClass::w = -1;
const int PlayerClass::IMPACT_WOUND_HITSCORE_DIE_NUM = 2;
const int PlayerClass::IMPACT_WOUND_HITSCORE_DIE_FACES = 6;

//PlayerType specific constants
const string PlayerClass::DEFAULT_NAME = "DEFAULT";

//first two columns are "fluff" columns to account for starting at 0
//first two rows are "fluff" rows to account for starting at 0
const int PlayerClass::IMPACT_TABLE[IMP_AND_CRIT_ROWS][IMP_AND_CRIT_COLS] =
{
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                        
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
    
    /*Power Rating Column 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12*/
    
    /*Die Roll Row 2*/{0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    
    /*Die Roll Row 3*/{0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, w},
    
    /*Die Roll Row 4*/{0, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, w, w},
    
    /*Die Roll Row 5*/{0, 0, 3, 4, 5, 6, 7, 8, 9, 10, w, w, w},
    
    /*Die Roll Row 6*/{0, 0, 4, 5, 6, 7, 8, 9, 10, w, w, w, w},
    
    /*Die Roll Row 7*/{0, 0, 5, 6, 7, 8, 9, 10, w, w, w, w, w},
    
    /*Die Roll Row 8*/{0, 0, 6, 7, 8, 9, 10, w, w, w, w, w, w},
    
    /*Die Roll Row 9*/{0, 0, 7, 8, 9, 10,  w, w, w, w, w, w, w},
    
    /*Die Roll Row 10*/{0, 0, 8, 9, 10, w, w, w, w, w, w, w, w},
    
    /*Die Roll Row 11*/{0, 0, 9, 10, w, w, w, w, w, w, w, w, w},
    
    /*Die Roll Row 12*/{0, 0, 10, w, w, w, w, w, w, w, w, w, w}
};

//first two columns are "fluff" columns to account for starting at 0
//first two rows are "fluff" rows to account for starting at 0
const int PlayerClass::CRIT_WOUND_TABLE[IMP_AND_CRIT_ROWS][IMP_AND_CRIT_COLS] =
{
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
                        
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
    /*Will Power Rating 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12*/
    
    /*Die Roll 2*/{0, 0, k, k, k, k, k, k, k, k, k, k, -1},
    
    /*Die Roll 3*/{0, 0, k, k, k, k, k, k, k, k, k, -1, -1},
    
    /*Die Roll 4*/{0, 0, k, k, k, k, k, k, k, k, -1, -1, -1},
    
    /*Die Roll 5*/{0, 0, k, k, k, k, k, k, k, -1, -1, -1, -1},
    
    /*Die Roll 6*/{0, 0, k, k, k, k, k, k, -1, -1, -1, -1, -1},
    
    /*Die Roll 7*/{0, 0, k, k, k, k, k, -1, -1, -1, -1, -1, -1},
    
    /*Die Roll 8*/{0, 0, k, k, k, k, -1, -1, -1, -1, -1, -1, -1},
    
    /*Die Roll 9*/{0, 0, k, k, k, -1, -1, -1, -1, -1, -1, -1, -1},
    
    /*Die Roll 10*/{0, 0, k, k, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    
    /*Die Roll 11*/{0, 0, k, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    
    /*Die Roll 12*/{0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
};
//first two columns are "fluff" columns to account for starting at 0

//Constructors

PlayerClass::PlayerClass():PLAYER_NAME(""), CONST_STATS(NULL)
{
	/*playerName = "DEFAULT";
	playType = EXPLORER;
	SetDefaultStats(playType);*/
}

PlayerClass::PlayerClass(const int INIT_CONST_STATS[], const int INIT_VAR_STATS[], string name):
PLAYER_NAME(PlayerClass::SetName(name)), CONST_STATS(INIT_CONST_STATS)
{
	SetDefaultStats(INIT_VAR_STATS);
}

PlayerClass::~PlayerClass()
{
    
}

//Observers

string PlayerClass::Name() const
{
	return(PLAYER_NAME);
}
	
int PlayerClass::Momentum() const
{
	return(stats[MOMENTUM]);
}
	
int PlayerClass::Power() const
{
	return(stats[POWER]);
}
	
int PlayerClass::RollPhysDam() const
{
	return(Dice::Roll(PLAYER_NAME, GameSpace::DAMAGE, stats[NUM_DICE], stats[DIE_FACES]));
}
	
int PlayerClass::Row() const
{
	return(stats[CUR_ROW]);
}
	
int PlayerClass::Col() const
{
	return(stats[CUR_COL]);
}

int PlayerClass::Defense() const
{
	return(stats[DEF_VALUE]);
}
	
GameSpace::DirType PlayerClass::Dir() const
{
	return(currentDirection);
}
	
int PlayerClass::MaxHealth() const
{
	return(CONST_STATS[MAX_HEALTH]);
}
	
bool PlayerClass::IsAlive() const
{
	return(stats[HEALTH] > 0);
}
	
int PlayerClass::Health() const
{
	return(stats[HEALTH]);
}
	
bool PlayerClass::IsDead() const
{
	return(stats[HEALTH] <= 0);
}
	
int PlayerClass::WillPower() const
{
	return(stats[WILLPOWER]);
}
	
bool PlayerClass::IsActive() const
{
	return(IsAlive() && (stats[WILLPOWER] > 0) && (activeStatus != false));
}
	
int PlayerClass::MaxSpeed() const
{
	return(CONST_STATS[MAX_SPEED]);
}

int PlayerClass::CurrentSpeed() const
{
	return(stats[SPEED]);
}

//Transformers

bool PlayerClass::MakeActive()
{
    bool returnValue;
	
	if(IsAlive())
	{
		activeStatus = true;
		returnValue = true;
	}
	else
	{
		activeStatus = false;
		returnValue = false;
	}

	return(returnValue);
}
	
bool PlayerClass::MakeInActive()
{
	activeStatus = false;
	return(true);
}

int PlayerClass::ResetCurrentSpeed()
{
	if(IsActive())
	{
		stats[SPEED] = CONST_STATS[1];
	}

	return(stats[SPEED]);
}

int PlayerClass::ResetMomentum()
{
	if(IsActive())
	{
		stats[MOMENTUM] = stats[SPEED];
	}
	return(stats[MOMENTUM]);
}
	
bool PlayerClass::MakeDead()
{
	stats[HEALTH] = 0;
	stats[WILLPOWER] = 0;
	stats[MOMENTUM] = 0;
	stats[SPEED] = 0;
	
	MakeInActive();

	return(true);
}
	
int PlayerClass::UseMomentum(int amount)
{    
    if(IsActive() && (amount > 0))
	{
		stats[MOMENTUM] = stats[MOMENTUM] - amount;
        
		if(stats[MOMENTUM] < 0)
		{
			stats[MOMENTUM] = 0;
		}
	}
	

	return(stats[MOMENTUM]);
}
	
int PlayerClass::Wounded(int damage)
{
	bool isInActive = false;
	bool isDead = false;
	
	if(IsActive() && (damage > 0))
	{
		stats[HEALTH] = stats[HEALTH] - damage;
		if(stats[HEALTH] <= 0)
		{
			isInActive = MakeInActive();
			isDead = MakeDead();
		}
	}
	
	return(stats[HEALTH]);
}
	
bool PlayerClass::SetCell(int newRow, int newCol)
{
	bool returnValue = false;
	
	if(((newRow > DEFAULT_ROW && newRow < GameSpace::NUMROWS) && (newCol > DEFAULT_COL && newCol < GameSpace::NUMCOLS))
        or (newRow == DEFAULT_ROW && newCol == DEFAULT_COL))
	{
		stats[CUR_ROW] = newRow;
		stats[CUR_COL] = newCol;
		returnValue = true;
	}
	else
	{
		returnValue = false;
	}

	return(returnValue);
}
	
int PlayerClass::Invigorate(int vigor)
{
    if(IsActive())
    {
        if(vigor > 0)
        {
            stats[HEALTH] = stats[HEALTH] + vigor;
        }
        if(stats[HEALTH] > CONST_STATS[0])
        {
            stats[HEALTH] = CONST_STATS[0];
        }
    }

	return(stats[HEALTH]);
}
	
bool PlayerClass::SetDir(DirType dir)
{
	bool returnValue = false;
	
	if(currentDirection != dir)
	{
		if((dir < 0) || (dir > 3))
        {
            currentDirection = GameSpace::DirType(0);
        }
        else
        {
            currentDirection = dir;
            returnValue = true;
        }
	}

	return(returnValue);
}

bool PlayerClass::Heal()
{
	bool returnValue = false;
	const int HEAL = 10;
	if(IsActive())
	{
		Invigorate(HEAL);
		returnValue = true;
        ResetCurrentSpeed();
	}

	return(returnValue);
}

int PlayerClass::SlowDown(int hazard)
{
	if(IsActive() && (hazard > 0))
	{
		stats[SPEED] = stats[SPEED] - hazard;
		if(stats[SPEED] < stats[MOMENTUM])
		{
			stats[MOMENTUM] = stats[SPEED];
		}
		if(stats[SPEED] < 0)
        {
            stats[SPEED] = 0;
            stats[MOMENTUM] = stats[SPEED];
        }
	}

	return(stats[SPEED]);
}

void PlayerClass::Write(ostream& out) const
{
    char direction;
	switch(currentDirection)
	{
		case NORTH:
			direction = 'N';
			break;
		case SOUTH:
			direction = 'S';
			break;
		case EAST:
			direction = 'E';
			break;
		case WEST:
			direction = 'W';
			break;
	}
	
	out << activeStatus << '#' << PLAYER_NAME << "#(" << stats[CUR_ROW] << ',';
	out << stats[CUR_COL] << ',' << direction << ")#" << CONST_STATS[0] << '#' << stats[HEALTH];
	out << '#' << stats[WILLPOWER] << '#' << stats[POWER] << '#';
	out << CONST_STATS[1] << '#' << stats[SPEED] << '#' << stats[MOMENTUM];
	out << '#' << stats[NUM_DICE] << 'd' << stats[DIE_FACES] << '#' << stats[DEF_VALUE];
	out << endl;
}

int PlayerClass::Fortify(int boost)
{
	if(IsActive() && boost > 0)
    {
        stats[DEF_VALUE] += boost;
    }

    return(stats[DEF_VALUE]);
}

int PlayerClass::Expose(int decline)
{
	if(IsActive() && decline > 0)
    {
        stats[DEF_VALUE] = stats[DEF_VALUE] - decline;
        if(stats[DEF_VALUE] < 0)
        {
            stats[DEF_VALUE] = 0;
        }
    }

    return(stats[DEF_VALUE]);
}

int PlayerClass::HitScore() const
{
    int hitScore = 0;
    
    if(IsActive())
    {
        hitScore = Dice::Roll(PLAYER_NAME, HITSCORE, IMPACT_WOUND_HITSCORE_DIE_NUM, IMPACT_WOUND_HITSCORE_DIE_FACES);
    }

    return(hitScore);
}

int PlayerClass::HitDamage() const
{
	int rollValue = 0;
    int damageReceived = 0;
    
    if(IsActive())
    {
        rollValue = RollPhysDam();
        damageReceived = rollValue + Power();
    }

    return(damageReceived);
}

int PlayerClass::Impact() const
{
	int impactWound = 0;
    int rollValue = 0;
    
    if(IsActive())
    {
        if(stats[POWER] > 2)
        {
            rollValue = Dice::Roll(PLAYER_NAME, IMPACT, IMPACT_WOUND_HITSCORE_DIE_NUM, IMPACT_WOUND_HITSCORE_DIE_FACES);
            impactWound = ImpactTableSearch(rollValue, stats[POWER]);
        }
            
        else
        {
            impactWound = 0;
        }
    }

    return(impactWound);
}

bool PlayerClass::CriticalWound()
{
	bool aliveStatus;
    
    if(IsAlive())
    {
        aliveStatus = true;
    }
    else
    {
        aliveStatus = false;
    }
    
    int critWound;
    int rollValue = 0;
    
    if(IsActive())
    {
        if(stats[HEALTH] > 10 && stats[WILLPOWER] >= 2)
        {
            rollValue = Dice::Roll(PLAYER_NAME, WOUND, IMPACT_WOUND_HITSCORE_DIE_NUM, IMPACT_WOUND_HITSCORE_DIE_FACES);
            critWound = CritWoundTableSearch(rollValue, stats[WILLPOWER]);
            
            if(critWound == k)
            {
                MakeDead();
                aliveStatus = false;
            }
            
            else if(critWound == -1)
            {
                stats[WILLPOWER] += critWound;
                if(stats[WILLPOWER] == 0)
                {
                    MakeDead();
                    aliveStatus = false;
                }
            }
        
        
        stats[HEALTH] = stats[HEALTH] - 10;
        stats[SPEED] = stats[SPEED] * .5;
        if(stats[MOMENTUM] > stats[SPEED])
        {
            stats[MOMENTUM] = stats[SPEED];
        }
        
        if(stats[HEALTH] <= 0)
        {
            MakeDead();
            aliveStatus = false;
        }
    }
    else
    {
        MakeDead();
        aliveStatus = false;
    }
       
    }
    
    return(aliveStatus);
}

int PlayerClass::WillPowerAdj(int adjustment)
{
	if(IsActive() && IsAlive())
    {
        stats[WILLPOWER] += adjustment;
        if(stats[WILLPOWER] > 12)
        {
            stats[WILLPOWER] = 12;
        }
        else if(stats[WILLPOWER] < 0)
        {
            stats[WILLPOWER] = 0;
            MakeDead();
        }
    }

    return(stats[WILLPOWER]);
}
//Overloaded operators
ostream& operator<<(ostream& out, const PlayerClass* p)
{	    
    if(p != NULL)
    {
        p->Write(out);
    }
	return(out);
}

bool PlayerClass::operator==(const PlayerClass& p) const
{
	return(Ucase(PLAYER_NAME) == Ucase(p.PLAYER_NAME));
}

bool PlayerClass::operator!=(const PlayerClass& p) const
{
	return(Ucase(PLAYER_NAME) != Ucase(p.PLAYER_NAME));
}

bool PlayerClass::operator<(const PlayerClass& p) const
{
	return(Ucase(PLAYER_NAME) < Ucase(p.PLAYER_NAME));
}

bool PlayerClass::operator>(const PlayerClass& p) const
{
	return(Ucase(PLAYER_NAME) > Ucase(p.PLAYER_NAME));
}

bool PlayerClass::operator<=(const PlayerClass& p) const
{
	return(Ucase(PLAYER_NAME) <= Ucase(p.PLAYER_NAME));
}

bool PlayerClass::operator>=(const PlayerClass& p) const
{
	return(Ucase(PLAYER_NAME) >= Ucase(p.PLAYER_NAME));
}

const PlayerClass& PlayerClass::operator=(const PlayerClass& p)
{
    if(this != &p)
    {
        CopyIntoMe(p);
    }
    
    return(*this);
}

//Helper Functions
string PlayerClass::SetName(string name)
{
    string returnName;
    returnName = TrimStr(name);
    
	if((returnName.size() < 1) || (name == " "))
	{
        throw INVALID_NAME;
	}
	if(returnName.size() > 10)
    {
        returnName = returnName.substr(0,10);
        returnName = TrimStr(returnName);
    }
    
	return(returnName);
}
	
void PlayerClass::SetDefaultStats(const int INIT_VAR_STATS[])
{    
    for(int i = 0; i < NUM_STATS; i++)
    {
        stats[i] = INIT_VAR_STATS[i];
    }
    
    activeStatus = false;
    currentDirection = DEFAULT_DIRECTION;
	
}

int PlayerClass::ImpactTableSearch(int rollValue, int power) const
{
	int impactValue = 0;
//      cout << "Power passed into ImpactTableSearch: " << power << endl;
//      cout << "RollValue passed into ImpactTableSearch: " << rollValue << endl;
    
    if(rollValue < 2 or rollValue > 12)
    {
        throw GameSpace::INVALID_ROLL;
    }
    else
    {
        impactValue = IMPACT_TABLE[rollValue][power];
    }
    
    return(impactValue);
}

int PlayerClass::CritWoundTableSearch(int rollValue, int willpower)
{
	int critWound = 0;
    
    if(rollValue < 2 or rollValue > 12)
    {
        throw GameSpace::INVALID_ROLL;
    }
    
    else
    {
        critWound = CRIT_WOUND_TABLE[rollValue][willpower];
    }

    return(critWound);
}

void PlayerClass::CopyIntoMe(const PlayerClass& p)
{
    *const_cast<string*>(&PLAYER_NAME) = p.PLAYER_NAME;
    activeStatus = p.activeStatus;
    currentDirection = p.currentDirection;
    
    for(int i = 0; i < NUM_STATS; i++)
    {
        stats[i] = p.stats[i];
    }
    
    *const_cast<const int**>(&CONST_STATS) = p.CONST_STATS;
}
