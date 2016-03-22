#pragma once
#include "strings.h"
#include "inventory.h"
#include <cmath>
#include <iostream>
const float constantLvl = 0.31;

typedef std::vector<ElementalDamage> resistanceList;
class Character 
{
protected:
	String m_name;
	float m_constantHealth;
	int m_health, m_level, m_exp;
	Inventory m_inventory;

public:

	void addWeapon(String name, weaponType wepType, ElementalDamage element, int damage) {
		m_inventory.addWeapon(name, wepType, element, damage);
	}
	void addArmor(String name, armorType armType, defenseInfo dInfo) {
		m_inventory.addArmor(name, armType, dInfo);
	}
	void equipItem(String name) {
		if (m_inventory.getItem(name) != nullptr)
		{
			m_inventory.equipItem(name);
		}
	}
	bool isDead() { return m_health == 0; }
	void changeHealth(damageInfo dInfo);
	void attack(Character& target);
	String name() { return m_name; }
	int getLevel() { return m_level; }
	Character(int health, String name);
	Character(int health, String name, int exp);
	void gainExp(int exp);
	/*level = constant * sqrt(XP)*/
	Character() {}
	~Character();

};
