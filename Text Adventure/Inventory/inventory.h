#pragma once
#include "../String/Strings.h"
#include "Items.h"
#include "Weapon.h"
#include "Armor.h"
#include <vector>
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
	void addWeapon(Item& item);
	void addItem(Item& item);
	void addArmor(String name, armorType armType, defenseInfo dInfo);
	void addArmor(Item& item);
	void equipItem(String itemName);
	int size() { return (int)m_ItemList.size(); }
	Item* getItem(int itemNameID);
	Item* getItem(String itemName);
	int getItemIndex(String itemName);
	Item* getEquipItem(int index) { return m_Equiptment[index]; }
};

