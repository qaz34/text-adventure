#pragma once
#include "items.h"
#include "strings.h"

enum class weaponType
{
	MELEE,
	RANGED,
	MAGIC
};

struct damageInfo
{
	int m_damage;
	ElementalDamage m_element;
	weaponType m_wepType;
};

class Weapon : public Item
{
protected:
	damageInfo m_info;
	
public:

	Weapon(String name, weaponType wepType, ElementalDamage element, int damage) : Item(name, 5) {
		m_info.m_wepType = wepType;
		m_info.m_element = element;
		m_info.m_damage = damage;
	};
	virtual void use(Character* target);
	virtual defenseInfo getInfo() {
		defenseInfo temp{ 0, {} };
		return temp;
	};

	~Weapon();

};

