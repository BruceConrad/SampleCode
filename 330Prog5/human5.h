/*
//Bruce Conrad human4.h
//This is the header file for the Human Class.
//Worked with: Kaize Yi for debugging purposes
*/

#ifndef HUMAN5_H
#define HUMAN5_H

#include "wpn.h"
#include "pack.h"
#include "player5.h"

class Human: public PlayerClass
{
    public:
        //Copy Constructor
        Human(const Human& h);
        
        //Destructor
        virtual ~Human();
        /*
        //Narrative: The destructor for HumanClass
        //Pre-condition: none
        //Post-condition: all dynamic memory has been deallocated
        */
        
        //Clone method
        virtual Human* Clone() const = 0;
        
        //Observers
        virtual const string WeaponName();
        /*
        //Narrative: Returns a weapon name
        //Pre-condition: Player is active
        //Post-condition: Weapon name is returned
        */
        virtual const string WeaponNameAndNum();
        /*
        //Narrative: Returns a weapon name and number
        //Pre-condition: Player is active
        //Post-condition: Weapon name and number is returned
        */
        virtual bool HasWeapon() const;
        /*
        //Narrative: Returns if player has a weapon
        //Pre-condition: Player is active
        //Post-condition: either player has a weapon and that is returned,
        //or player does not have a weapon and NULL is returned
        */
        bool IsAlive() const;
        /*
        //Narrative: Returns if the player is alive
        //Pre-condition: player is active
        //Post-condition:either true is returned because player is alive,
        //or false is returned because player is dead
        */
        bool IsDead() const;
        /*
        //Narrative: Returns if the player is dead
        //Pre-condition: none
        //Post-condition: either true is returned because player is dead,
        //or false is returned because player is alive
        */
        bool IsActive() const;
        /*
        //Narrative: Returns if the player is active
        //Pre-condition: none
        //Post-condition: returns true if player is active, false otherwise
        */
        virtual bool IsMyEnemy(const PlayerClass* p) const;
        /*
        //
        */
        vector<string> Pack();
        /*
        //
        */
        int WeaponSkill() const;
        /*
        //Narrative: Return the weapon skill of the weapon in the player's hand.
        //Return 0 if there is no weapon.
        //Pre-condition: none
        //Post-condition: weapon skill is returned, or 0 is returned
        */
        virtual string TypeStr() const = 0;
        //Transformers
        Weapon* GrabWeapon(Weapon* weapon);
        /*
        //
        */
        Weapon* ChangeWeapon(string weaponName);
        /*
        //
        */
        Weapon* DropWeapon();
        /*
        //Narrative: An active player drops their weapon and leaves the player
        //with no weapon. The method returns the weapon dropped, or NULL if the
        //player is not active or there was no weapon to drop.
        //Pre-condition: player is alive
        //Post-condition: a weapon is returned, or NULL is returned because
        //the player is inactive or did not have a weapon to drop
        */
        bool ImprovedSkill(int improvement);
        /*
        //
        */
        bool MakeActive();
        /*
        //
        */
        bool MakeInActive();
        /*
        //
        */
        virtual bool Heal();
        /*
        //
        */
        int RollPhysDam();
        /*
        //
        */
        
        //Combat
        int HitScore();
        /*
        //
        */
        virtual int HitDamage() const;
        /*
        //
        */
        int Impact() const;
        /*
        //
        */
        bool CriticalWound();
        /*
        //
        */
        
        //Output
        virtual void Write(ostream& out) const;
        /*
        //
        */
        
        //Overloaded operator(s)
        const Human& operator=(const Human& h);
        
    protected:
        Human(const int INIT_CONST_STATS[], const int INIT_VAR_STATS[],
                   string NAME);
        /*
        //
        */
    
    
    private:
        Human();
        /*
        //
        */
        
        //Class Instance Data Members
        int carryWeight;
        PackClass* const CURRENT_PACK;
        Weapon* currentWpn;
        int currentWpnSkill;
        map<string, int> weaponSkillMap;
        
        //Default base constants
        static const int DEFAULT_SKILL;
        
        //Helper Methods
        int SetWeight(int& weight);
        /*
        //
        */
        void LoadWeaponsMap(map<string,int>& wpnMap, Weapon* weapon);
        /*
        //Narrative: A helper function to load a weapon into the weapon skill
        //map for humans
        //Pre-condition: none
        //Post-condition: a weapon has been loaded into a human character's
        //skill map
        */
        void CopyIntoMe(const Human& h);
};

#endif
