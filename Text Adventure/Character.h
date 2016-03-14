#pragma once
#include "strings.h"
#include "inventory.h"
#include <iostream>
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
	void addPotion(String name, int stack) {
		m_inventory.addPotion(name, stack);
	}
	void changeHealth(int ammount);
	Character(int health, String name);
	Character() {}
	~Character();
};

