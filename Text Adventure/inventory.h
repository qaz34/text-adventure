#pragma once
#include "strings.h"
#include "items.h"
#include "weapon.h"
#include "armor.h"
#include <iostream>
class Inventory
{
	std::vector<Item*> m_ItemList;
	/*0: Helmet
	1: Chest
	2: Arms
	3: Legs
	4: Feet
	5: Weapon
	*/
	Item* m_Equiptment[6];
public:
	Inventory();
	~Inventory();
	void addWeapon(String name, weaponType wepType, ElementalDamage element, int damage);
	void addArmor(String name, armorType armType, defenseInfo dInfo);
	void equipItem(String itemName);
	Item* getItem(int itemNameID);
	Item* getItem(String itemName);
	int getItemIndex(String itemName);
	Item* getEquipItem(int index) { return m_Equiptment[index]; }
};

