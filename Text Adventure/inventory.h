#pragma once

#include <vector>
#include "strings.h"
#include "items.h"
#include "weapon.h"
#include "potion.h"
#include <iostream>
class Inventory
{
	std::vector<Item*> m_ItemList;
public:
	Inventory();
	~Inventory();
	void addWeapon(String name, weaponType wepType, ElementalDamage element, int damage);
	void addPotion(String name, int stack);
	Item* getItem(int itemNameID) {
		return m_ItemList[itemNameID];
	}

};

