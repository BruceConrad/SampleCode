/*
//Bruce Conrad player4.h
//This is the header file for the PlayerClass.
//Worked with: Kaize Yi for debugging purposes
*/

#ifndef PLAYER5_H
#define PLAYER5_H

#include "gamespace.h"
#include "dice.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

class PlayerClass
{
	private:
    //Class Instance Constant
	static const string DEFAULT_NAME;
    
    //Data Types
    enum StatsType{HEALTH, WILLPOWER, SPEED, MOMENTUM, CUR_ROW, CUR_COL, POWER, DEF_VALUE, NUM_DICE, DIE_FACES, INVALID_STAT};
    
    enum ConstStatsType{MAX_HEALTH, MAX_SPEED, INVALID_CONST_STAT};
	
	public:
	
	//Destructor
    virtual ~PlayerClass();
    /*
    //Narrative: The destructor for PlayerClass
    //Pre-condition: none
    //Post-condition: all dynamic memory has been deallocated associated
    //with the invocation of the destructor
    */
	
    //Clone method
    virtual PlayerClass* Clone() const = 0;
    
	//Observers
	string Name() const;
	/*
	//Narrative: Returns the player's name
	//Pre-condition: player character exists
	//Post-condition: player's name is returned
	*/
	int Momentum() const;
	/*
	//Narrative: returns the player's momentum
	//Pre-condition: player character exists
	//Post-condition: player's momentum is returned
	*/
	int Power() const;
	/*
	//Narrative: returns the player's power
	//Pre-condition: player character exists
	//Post-condition: player's power is returned
	*/
	int Row() const;
	/*
	//Narrative: returns the player’s cell row
	//Pre-condition: player character is in a valid cell
	//Post-condition: player character’s row is returned
	*/
	int Col() const;
	/*
	//Narrative: returns the player’s cell column
	//Pre-condition: player character is in a valid cell
	//Post-condition: player character’s column is returned
	*/
	int Defense() const;
	/*
	//Narrative: returns the player character’s defense value
	//Pre-condition: player character exists
	//Post-condition: player’s defense value is returned
	*/
	GameSpace::DirType Dir() const;
	/*
	//Narrative: returns the direction the player is facing
	//Pre-condition: player character exists
	//Post-condition:  player character’s direction is returned
	*/
	int MaxHealth() const;
	/*
	//Narrative: returns the player’s maximum health
	//Pre-condition: player character exists
	//Post-condition: player character’s maximum health is returned
	*/
	virtual bool IsAlive() const;
	/*
	//Narrative: returns true is player is alive, false otherwise
	//Pre-condition: player character exists
	//Post-condition: returns true if player character is alive, false otherwise
	*/
	int Health() const;
	/*
	//Narrative: returns player’s health
	//Pre-condition: player character exists
	//Post-condition: player’s health is returned
	*/

	virtual bool IsDead() const;
	/*
	//Narrative: returns true if player is dead, false otherwise
	//Pre-condition: player character exists
	//Post-condition: either true is returned because player is dead, or
	//false is returned because player is alive
	*/
	int WillPower() const;
	/*
	//Narrative: returns the player’s willpower
	//Pre-condition: player character exists
	//Post-condition: player character’s willpower is returned
	*/
	virtual bool IsActive() const;
	/*
	//Narrative: Returns true if player character is active, false otherwise
	//Pre-condition: player character exists, player character is alive,
	//player character is considered in play
	//Post-condition: true is returned because player character is active,
	//or false is returned because player character is not active
	*/
	int MaxSpeed() const;
	/*
	//Narrative: returns the player’s max speed
	//Pre-condition: player character exists
	//Post-condition: player character’s max speed is returned
	*/
	int CurrentSpeed() const;
	/*
	//Narrative: returns the player’s current speed
	//Pre-condition: player character exists
	//Post-condition: player character’s current speed is returned
	*/
    virtual bool IsMyEnemy(const PlayerClass* p) const = 0;
    /*
	//Narrative: Determines whether another player is an enemy of the current
	//player or if it is not an enemy
	//Pre-condition: player is active
	//Post-condition: either true is returned because another player is an
	//enemy or false is returned because the other player is not an enemy
	*/
    virtual string TypeStr() const = 0;
    
	//Transformers
	virtual bool MakeActive();
	/*
	//Narrative: Sets player character to be active unless player character
	//is dead. Returns true if player is active, false otherwise
	//Pre-condition: player character exists
	//Post-condition: true is returned because player is active and player
	//is set to active, or false is returned because player is inactive
	*/
	virtual bool MakeInActive();
	/*
	//Narrative: Sets player to be inactive, returns true to indicate the
	//player is inactive (will always return true)
	//Pre-condition: player character exists
	//Post-condition: player set to inactive, true is returned
	*/
	
	int ResetCurrentSpeed();
	/*
	//Narrative: If player character is active, current speed is reset to max
	//speed. Returns the current speed.
	//Pre-condition: player character exists
	//Post-condition: player's current speed is reset, current speed is
	//returned
	*/
	
	int ResetMomentum();
	/*
	//Narrative: If the player character is active, then momentum is reset
	//to the current speed. Returns the momentum
	//Pre-condition: player character exists
	//Post-condition momentum is reset to current speed and momentum is 
	//returned
	*/
	bool MakeDead();
	/*
	//Narrative: Sets player character’s health, momentum, willpower, and 
	//current speed to zero to indicate player is dead. Player is then set to 
	//inactive. Returns true to indicate player is dead (always returns true)
	//Pre-condition: player character exists
	//Post-condition: player character is dead, player character set to 
	//inactive, true is returned
	*/
	int UseMomentum(int amount);
	/*
	//Narrative: if the player character is active, and the amount is greater 
	//than 0, then the amount is deducted from the momentum. The momentum 
	//cannot drop below 0. Return the momentum
	//Pre-condition: player character exists, amount is valid number i.e. 
	//non-negative (0 or greater)
	//Post-condition: amount has been deducted from momentum, current momentum 
	//is returned
	*/
	int Wounded(int damage);
	/*
	//Narrative: If player character is active, and damage is greater than 0, 
	//damage is deducted from health. If player character’s health drops to 0 
	//or below, player is dead and is made inactive. Return the health
	//Pre-condition: Player character exists and is active
	//Post-condition: player’s current health is updated, and player’s current 
	//health is returned
	*/
	bool SetCell(int newRow, int newCol);
	/*
	//Narrative: Updates player character’s current coordinates regardless of 
	//player’s state (i.e. active or inactive). If both newRow and newCol > -1 
	//then coordinates are set. If both newRow and newCol = -1, then this 
	//indicates the player is not on the board. Otherwise, coordinates are not 
	//set (i.e. newRow, newCol, or both are invalid, coordinates not changed)
	//Pre-condition: player character exists
	//Post-condition: either coordinates are set and true is returned, or 
	//coordinates are not set and false is returned
	*/
	int Invigorate(int vigor);
	/*
	//Narrative: If player character is active and vigor is greater than 0, 
	//vigor is added to current health. Returns the health
	//Pre-condition: player character exists and is active
	//Post-condition: player character’s current health is updated, 
	//and health is returned
	*/
	bool SetDir(DirType dir);
	/*
	//Narrative: Updates player character’s current direction, regardless of 
	//player state. If direction is updated returns true, false otherwise
	//Pre-condition: player character exists
	//Post-condition: either player’s direction is updated and true is 
	//returned, or player’s direction is not updated and false is returned
	*/
	virtual bool Heal();
	/*
	//Narrative: If player is active, updates the appropriate values to 
	//indicate player has healed. Returns true, unless player could not 
	//be healed due to being inactive or dead
	//Pre-condition: player character exists
	//Post-condition: player has been healed and true is returned, or 
	//player was not healed and false is returned
	*/
	int SlowDown(int hazard);
	/*
	//Narrative: If player is active, and hazard is greater than 0, then 
	//hazard is deducted from current speed. Current speed cannot drop 
	//below 0, and momentum should never be above current speed. If necessary, 
	//reduce the momentum to the value of current speed. Returns the current 
	//speed.
	//Pre-condition: player character exists and is active
	//Post-condition: hazard is deducted from current speed, and current speed 
	//is returned
	*/
	virtual void Write(ostream& out) const;
	/*
	//Narrative: Outputs the player data
	//Pre-condition: player character exists
	//Post-condition: player character’s data is output
	*/
    int Fortify(int boost);
    /*
    //Narrative: If the player is active and boost is greater than zero,
    //the boost is added to defense. Return the defense.
    //Pre-condition: player is active
    //Post-condition: either player boost is added to defense, or there is
    //no change in defense
    */
    int Expose(int decline);
    /*
    //Narrative: If the player is active and decline is greater than zero,
    //the decline is deducted from the defense. If the player's defense
    //drops below zero, set it to zero to indicate the player cannot defend
    //itself. Return the defense.
    //Pre-condition: player is active
    //Post-condition: player defense has been reduced, defense is returned
    */
    virtual int RollPhysDam() const;
	/*
	//Narrative: returns the player’s physical damage
	//Pre-condition: player character is active
	//Post-condition: player’s physical damage is returned
	*/
    int WillPowerAdj(int adjustment);
    /*
    //Narrative: If the player is active, the adjustment is applied to
    //willpower. Valid will power is between 0 and 12. If will power
    //exceeds 12, reset will power to 12. If the player's will power drops
    //below zero, reset to 0, and the player is dead and no longer active.
    //Return the will power.
    //Pre-condition: player is active
    //Post-condition: will power is betwen 0 and 12, will power is returned,
    //IF will power == 0 then player is dead
    */
    
    //Combat
    virtual int HitScore() const;
    /*
    //Narrative: If the player is active, the hit score is rolled and
    //returned, otherwise 0 is returned
    //Pre-condition: player is active
    //Post-condition: hit score is rolled and returned, or 0 is returned
    */
    virtual int HitDamage() const;
    /*
    //Narrative: If the player is active, the damage inflicted is returned,
    //otherwise 0 is returned. Damage is calculated by using the Weapon Skill
    //for the weapon or player's power if there is no weapon; add the score
    //from the Damage Value of the weapon used or roll the Physical Damage
    //of player if no weapon.
    //Pre-condition: player is active
    //Post-condition: weapon damage is returned, player either received no
    //damage or received damage based on another player's weapon or another
    //player's physical power
    */
    virtual int Impact() const;
    /*
    //Narrative: If the player is active, the impact of a critical wound
    //inflicted is returned, otherwise 0 is returned. Return value is
    //determined from Impact Table using either weapon power(if player
    //has a weapon) or player's base power. A player can inflict no critical
    //wound if they are inactive or have no weapon and player power is less
    //than two. Return -1 if the wound is a mortal wound ('w' in strike
    //table).
    //Pre-condition: player is active
    //Post-condition: If player receives critical wound, impact of wound is
    //returned. Otherwise, 0 is returned. Return values are based on Impact
    //Table. -1 is returned if wound is a mortal wound.
    */
    virtual bool CriticalWound();
    /*
    //Narrative: Applies the outcome of a critical wound on an active player.
    //The player's health is reduced by 10 points and the current speed is
    //decreased by half(round down). If player is still alive, then consult
    //the Critical Wound Table for the damage to willpower or the life ending
    //damage. Return true if the player is still alive, and false if the
    //player is dead.
    //Pre-condition: player is active
    //Post-condition: true is returned if player is still alive, false
    //otherwise; 10 points of damage received and speed decreased by
    //half; if player is still alive after this, Critical Wound Table is
    //consulted for damage to willpower or life ending damage
    */
    
    //Overloaded Operators
    const PlayerClass& operator=(const PlayerClass& p);
	/*
	//Narrative: The overloaded assignment operator for the PlayerClass
	//Pre-condition: none
	//Post-condition: one PlayerClass object is assigned to another object
	*/
    bool operator==(const PlayerClass& p) const;
    /*
    //Narrative: Relational operator for == that will compare two PlayerClass
    //object using alphabetic order by name (not case-sensitive)
    //Pre-condition: none
    //Post-condition: two PlayerClass objects have been compared
    //alphabetically for equality
    */
     bool operator!=(const PlayerClass& p) const;
    /*
    //Narrative: Relational operator for != that will compare two PlayerClass
    //object using alphabetic order by name (not case-sensitive)
    //Pre-condition: none
    //Post-condition: two PlayerClass objects have been compared
    //alphabetically for inequality
    */
     bool operator<(const PlayerClass& p) const;
    /*
    //Narrative: Relational operator for < that will compare two PlayerClass
    //object using alphabetic order by name (not case-sensitive)
    //Pre-condition: none
    //Post-condition: two PlayerClass objects have been compared
    //alphabetically for one being less than the other
    */
     bool operator>(const PlayerClass& p) const;
    /*
    //Narrative: Relational operator for > that will compare two PlayerClass
    //object using alphabetic order by name (not case-sensitive)
    //Pre-condition: none
    //Post-condition: two PlayerClass objects have been compared
    //alphabetically for one being greater than the other
    */
     bool operator<=(const PlayerClass& p) const;
    /*
    //Narrative: Relational operator for <= that will compare two PlayerClass
    //object using alphabetic order by name (not case-sensitive)
    //Pre-condition: none
    //Post-condition: two PlayerClass objects have been compared
    //alphabetically for one being less than or equal to the other
    */
     bool operator>=(const PlayerClass& p) const;
    /*
    //Narrative: Relational operator for >= that will compare two PlayerClass
    //object using alphabetic order by name (not case-sensitive)
    //Pre-condition: none
    //Post-condition: two PlayerClass objects have been compared
    //alphabetically for one being greater than or equal to the other
    */
	
    protected:
    PlayerClass(const int INIT_CONST_STATS[], const int INIT_VAR_STATS[], string name = DEFAULT_NAME);
	/*
	//Narrative: The two-parameter constructor for the PlayerClass
	//Pre-condition: none
	//Post-condition: an object of type PlayerClass is created wirth a name
	//and initial player type, if an empty string is entered name is set to
	//DEFAULT, and if player type is invalid then player type defaults to
	//EXPLORER
	*/
    int ImpactTableSearch(int rollValue, int power) const;
    /*
    //Narrative: a helper method to search the impact table for the method Impact
    //Pre-condition: Impact() has been called
    //Post-condition: Impact table has been searched, a value from the
    //table is returned
    */
    int CritWoundTableSearch(int rollValue, int willpower);
    /*
    //Narrative: helper method for the CriticalWound() method that searches
    //the critical wound table
    //Pre-condition: CriticalWound() method is called
    Post-condition: a value from the critical wound table is returned
    */
	private:
	//Class Constants
	
	//Default base constants
	static const int DEAD;
	static const GameSpace::DirType DEFAULT_DIRECTION;
	static const int DEFAULT_ROW;
	static const int DEFAULT_COL;
    static const int NUM_STATS = 10;
    static const int IMP_AND_CRIT_ROWS = 13;
    static const int IMP_AND_CRIT_COLS = 13;
    static const int k;
    static const int w;
    static const int IMPACT_TABLE[IMP_AND_CRIT_ROWS][IMP_AND_CRIT_COLS];
    static const int CRIT_WOUND_TABLE[IMP_AND_CRIT_ROWS][IMP_AND_CRIT_COLS];
    static const int IMPACT_WOUND_HITSCORE_DIE_NUM;
    static const int IMPACT_WOUND_HITSCORE_DIE_FACES;
	
	//Class Instance Data Members
	const string PLAYER_NAME;
	bool activeStatus;
	GameSpace::DirType currentDirection;
    int stats[NUM_STATS];
    const int* const CONST_STATS;
    
    //Default Constructor
    PlayerClass();
	/*
	//Narrative: The default constructor for the PlayerClass
	//Pre-condition: none
	//Post-condition: An object has been created of type PlayerClass with a
	//default name DEFAULT and default PlayerType EXPLORER
	*/
    
    //Helper Methods
	string SetName(string name);
	/*
	//Narrative: a helper function for the constructors to set the name
	//Pre-condition: none
	//Post-condition: name is set
	*/
	void SetDefaultStats(const int INIT_VAR_STATS[]);
	/*
	//Narrative: a helper function for the 2-parameter constructor to set the 
	//default stats of the player characters
	//Pre-condition: none
	//Post-condition: Default stats are set for player character
	*/
    void CopyIntoMe(const PlayerClass& p);
    /*
    //Narrative: a helper function to make a deep copy of a PlayerClass object
    //Pre-condition: the copy constructor or overloaded assignment operator
    //has been invoked
    //Post-condition: a deep copy of the object has been made for the
    //copy constructor or overloaded assignment operator
    */
};

//Overloaded Assignment Operator
ostream& operator<<(ostream& out, const PlayerClass* p);
/*
//Narrative: Outputs the player data
//Pre-condition: player character exists
//Post-condition: player character’s data is output
*/
#endif
