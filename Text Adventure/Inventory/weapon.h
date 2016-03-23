#pragma once
#include "Items.h"
#include "../String/Strings.h"

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
	int random(int min, int max) {
		return rand() % max + min;
	}
	Weapon(String name, weaponType wepType, ElementalDamage element, int damage) : Item(name, 5) {
		m_info.m_wepType = wepType;
		m_info.m_element = element;
		m_info.m_damage = damage;
	};
	virtual void use(Character& target);
	virtual defenseInfo getInfo() {
		defenseInfo temp{ m_info.m_damage, {m_info.m_element} };
		return temp;
	};

	~Weapon();

};

