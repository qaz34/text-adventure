#pragma once
#include "strings.h"
#include "inventory.h"
#include <iostream>
typedef std::vector<ElementalDamage> resistanceList;
class Character
{
protected:
	String m_name;
	int m_health;
	Inventory m_inventory;

public:
	void addWeapon(String name, weaponType wepType, ElementalDamage element, int damage) {
		m_inventory.addWeapon(name, wepType, element, damage);
	}
	void equipItem(String name) {
		if (m_inventory.getItem(name) != nullptr)
		{
			m_inventory.equipItem(name);
		}
	}
	void changeHealth(damageInfo dInfo);
	void attack(Character& target);
	Character(int health, String name);
	Character() {}
	~Character();
	
};
