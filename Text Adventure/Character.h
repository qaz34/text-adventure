#pragma once
#include "strings.h"
#include "inventory.h"
#include <iostream>
class Character
{
protected:
	String m_name;
	int m_health, m_armor;
	float m_armorReduction;
	std::vector<ElementalDamage*> m_resistances;
public:
	Inventory m_inventory;
	void addWeapon(String name, weaponType wepType, ElementalDamage element, int damage) {
		m_inventory.addWeapon(name, wepType, element, damage);
	}
	void addPotion(String name, int stack) {
		m_inventory.addPotion(name, stack);
	}
	virtual void changeHealth(int ammount);
	void takeDamage(int ammount, ElementalDamage type) {
		int counter = 0;
		for (ElementalDamage* element : m_resistances)
		{
			if (*element == type)
			{
				m_health -= (int)((ammount * (1 - m_armorReduction))/2);
			}
			else {
				counter++;
			}
		}
		if (counter == m_resistances.size())
		{
			m_health -= ammount * (1 - m_armor);
		}
	}
	Character(int health, int armor, String name);
	Character(int health, int armor, String name, std::vector<ElementalDamage> resistances);
	Character() {}
	~Character();
};

