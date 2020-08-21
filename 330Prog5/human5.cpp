/*
//Bruce Conrad human4.h
//This is the implementation file for the Human Class.
//Worked with: Kaize Yi for debugging purposes
*/

#include "human5.h"


//Default base constants
const int Human::DEFAULT_SKILL = 1;


//Constructors
Human::Human(const int INIT_CONST_STATS[], const int INIT_VAR_STATS[],
           string NAME):PlayerClass(INIT_CONST_STATS, INIT_VAR_STATS, NAME),
           CURRENT_PACK(NULL), currentWpn(NULL), carryWeight(SetWeight(carryWeight)),
           currentWpnSkill(0)
{
    *const_cast<PackClass**>(&CURRENT_PACK) = new PackClass(carryWeight);
}

Human::Human():PlayerClass(NULL, NULL, ""), CURRENT_PACK(NULL), currentWpn(NULL), carryWeight(0),
               currentWpnSkill(0)
{
    
}

Human::Human(const Human& h): PlayerClass(h), CURRENT_PACK(NULL), currentWpn(NULL)
{
    CopyIntoMe(h);
}

//Destructor
Human::~Human()
{
    delete CURRENT_PACK;
    *const_cast<PackClass**>(&CURRENT_PACK) = NULL;
    
    delete currentWpn;
    currentWpn = NULL;
}

//Observers
const string Human::WeaponName()
{
    string returnWeapon = "";
    if(HasWeapon())
    {
        returnWeapon = currentWpn->Name();
    }
    return(returnWeapon);
}

const string Human::WeaponNameAndNum()
{
    string returnWeapon = "";
    if(HasWeapon())
    {
        returnWeapon = currentWpn->NameAndNum();
    }
    return(returnWeapon);
}

bool Human::HasWeapon() const
{
    bool returnValue = false;
    
    if(PlayerClass::IsActive() && currentWpn != NULL)
    {
        returnValue = true;
    }
    return(returnValue);
}

bool Human::IsAlive() const
{
    PlayerClass::IsAlive();
    
}

bool Human::IsDead() const
{
    PlayerClass::IsDead();
}

bool Human::IsActive() const
{
    PlayerClass::IsActive();
}

bool Human::IsMyEnemy(const PlayerClass* p) const
{
    static bool beenHere = false;
	bool enemy = false;
    const Human* h = dynamic_cast<const Human*>(p);
	if((h == NULL) && (p != NULL))
    {
		return(true);
    }
	
    else if((p != NULL) && !beenHere)
        {
		beenHere = true;
		enemy = p->IsMyEnemy(this);
        }
	else if(beenHere)
    {
		beenHere = false;
    }
	else
    {
		return(false);
    }
	return(beenHere && !h);
}

vector<string> Human::Pack()
{
    vector<string> returnVector;
    
    returnVector = CURRENT_PACK->PackInventory();
    return(returnVector);
    
}

int Human::WeaponSkill() const
{
    map<string, int>::const_iterator iter;
    int returnValue = 0;
    bool found = false;
    
    if(HasWeapon())
    {
        for(iter = weaponSkillMap.begin(); iter != weaponSkillMap.end() && !found; iter++)
        {
            if(Ucase(currentWpn->Name()) == iter->first)
            {
                returnValue = iter->second;
                found = true;
            }
        }
    }
    return(returnValue);
}

//Transformers
Weapon* Human::GrabWeapon(Weapon* weapon)
{
    Weapon* returnWeapon = weapon;
    bool startingSkill;
    
    if(weapon != NULL)
    {
        if(IsActive())
        {
            if(HasWeapon())
            {
                if(CURRENT_PACK->AddWeapon(currentWpn))
                {
                    returnWeapon = NULL;
                }
                else
                {
                    returnWeapon = DropWeapon();
                }
                currentWpn = weapon;
                currentWpnSkill = WeaponSkill();
                
                if(currentWpnSkill == 0)
                {
                    LoadWeaponsMap(weaponSkillMap, currentWpn);
                    startingSkill = ImprovedSkill(1);
                }
                
            }
            else if(!HasWeapon())
            {
                returnWeapon = NULL;
                currentWpn = weapon;
                currentWpnSkill = WeaponSkill();
                
                if(currentWpnSkill == 0)
                {
                    LoadWeaponsMap(weaponSkillMap, currentWpn);
                    startingSkill = ImprovedSkill(1);
                }
            }
        }
    }
    else
    {
        throw INVALID_WPN;
    }

    return(returnWeapon);
}

Weapon* Human::ChangeWeapon(string weaponName)
{
    Weapon* returnWeapon = NULL;
    
    if(IsActive())
    {
        if(Ucase(WeaponName()) != Ucase(weaponName))
        {
            if(CURRENT_PACK->InPack(weaponName))
            {
                returnWeapon = currentWpn;
                currentWpn = CURRENT_PACK->RemoveWeapon(weaponName);
                
                if(CURRENT_PACK->AddWeapon(returnWeapon))
                {
                    returnWeapon = NULL;
                }
            }
        }
    }
    return(returnWeapon);
}

Weapon* Human::DropWeapon()
{
	Weapon* weaponDropped = NULL;
    
    if(IsActive())
    {
        if(HasWeapon())
        {
            weaponDropped = currentWpn;
            currentWpn = NULL;
        }
    }

    return(weaponDropped);
}

bool Human::ImprovedSkill(int improvement)
{
    bool skillIsImproved = false;
    map<string, int>::iterator iter;
    
    if(IsActive() && currentWpn != NULL)
    {
        if(improvement > 0)
        {
            currentWpnSkill = currentWpnSkill + improvement;
            for(iter = weaponSkillMap.begin(); iter != weaponSkillMap.end(); iter++)
            {
                if(Ucase(currentWpn->Name()) == iter->first)
                {
                    iter->second = currentWpnSkill;
                }
            }
            skillIsImproved = true;
        }
        else if(improvement < 0)
        {
            currentWpnSkill = currentWpnSkill + improvement;
            for(iter = weaponSkillMap.begin(); iter != weaponSkillMap.end(); iter++)
            {
                if(Ucase(currentWpn->Name()) == iter->first)
                {
                    iter->second = currentWpnSkill;
                }
            }
        }
        if(currentWpnSkill < 0)
        {
            currentWpnSkill = 1;
            for(iter = weaponSkillMap.begin(); iter != weaponSkillMap.end(); iter++)
            {
                if(Ucase(currentWpn->Name()) == iter->first)
                {
                    iter->second = currentWpnSkill;
                }
            }
        }
    }

    return(skillIsImproved);
}

bool Human::MakeActive()
{
    PlayerClass::MakeActive();
}

bool Human::MakeInActive()
{
    PlayerClass::MakeInActive();
}

bool Human::Heal()
{
    PlayerClass::Heal();
}

int Human::RollPhysDam()
{
    PlayerClass::RollPhysDam();
}

int Human::HitScore()
{
    PlayerClass::HitScore();
}

int Human::HitDamage() const
{
    int damageReceived = 0;
    int rollValue = 0;
    
    if(IsActive())
    {
        if(HasWeapon())
        {
            if(currentWpn->IsRange())
            {
                rollValue = currentWpn->RollWeaponDamage(Name());
                damageReceived = rollValue + PlayerClass::Power();
                return(damageReceived);
            }
            else if(currentWpn->IsMelee())
            {
                rollValue = currentWpn->RollWeaponDamage(Name());
                damageReceived = rollValue + WeaponSkill();
                return(damageReceived);
            }
        }
        else
        {
            damageReceived = PlayerClass::HitDamage();
        }
    }
}

int Human::Impact() const
{
    int impactWound = 0;
    int rollValue = 0;
    
    
        if(PlayerClass::IsActive())
        {
            if(!HasWeapon())
            {
                impactWound = PlayerClass::Impact();
            }
            else if(HasWeapon())
            {
                if(currentWpn->Power() > 2)
                {
                    rollValue = Dice::Roll(Name(), IMPACT, 2, 6);
                    if(currentWpn->Power() > 12)
                    {
                        impactWound = ImpactTableSearch(rollValue, 12);
                    }
                    else
                    {
                        impactWound = ImpactTableSearch(rollValue, currentWpn->Power());
                    }
                }
            }
        }


    return(impactWound);
}

bool Human::CriticalWound()
{
    PlayerClass::CriticalWound();
}

//Output
void Human::Write(ostream& out) const
{
    PlayerClass::Write(out);
    
    map<string, int>::const_iterator iter;
    
    if(currentWpn != NULL && weaponSkillMap.size() > 0)
    {
		out << '\t';
		out << currentWpn->NameAndNum() << '#' << currentWpnSkill;
		
		for(iter = weaponSkillMap.begin(); iter != weaponSkillMap.end(); iter++)
        {
            if(iter->second > 0)
            {
                out << '#' << Ucase(iter->first) << '#' << iter->second;
            }
        }
        out << endl;
    }
	else if(currentWpn == NULL && weaponSkillMap.size() > 0)
	{
		out << '\t' << '#';
		for(iter = weaponSkillMap.begin(); iter != weaponSkillMap.end(); iter++)
        {
            if(iter->second > 0)
            {
                out << '#' << Ucase(iter->first) << '#' << iter->second;
            }
        }
        out << endl;
	}
}

//Overloaded operator(s)
const Human& Human::operator=(const Human& h)
{
    if(this != &h)
    {
        CopyIntoMe(h);
        PlayerClass::operator=(h);
        
    }
    return(*this);
}

//Helper Methods
int Human::SetWeight(int& weight)
{
    weight = 10 * RollPhysDam();
    return(weight);
}

void Human::LoadWeaponsMap(map<string,int>& wpnMap, Weapon* weapon)
{
    map<string, int>::iterator iter;
    bool found = false;
    
    for(iter = weaponSkillMap.begin(); iter != weaponSkillMap.end() && !found; iter++)
    {
        if(Ucase(weapon->Name()) == Ucase(iter->first))
        {
            found = true;
        }
    }
    
    if(!found)
    {
        wpnMap.insert(make_pair(Ucase(weapon->Name()), DEFAULT_SKILL));
        wpnMap[Ucase(weapon->Name())] = DEFAULT_SKILL;
    }
}

void Human::CopyIntoMe(const Human& h)
{
    carryWeight = h.carryWeight;
    
    if(CURRENT_PACK != NULL)
    {
        delete CURRENT_PACK;
        *const_cast<PackClass**>(&CURRENT_PACK) = NULL;
    }
    
    if(h.CURRENT_PACK != NULL)
    {
        *const_cast<PackClass**>(&CURRENT_PACK) = new PackClass(*(h.CURRENT_PACK));
    }
        
    if(currentWpn != NULL)
    {
        delete currentWpn;
        currentWpn = NULL;
    }
        
    if(h.currentWpn != NULL)
    {
        currentWpn = new Weapon(*(h.currentWpn));
    }
        
    currentWpnSkill = h.currentWpnSkill;
    weaponSkillMap = h.weaponSkillMap;
}
