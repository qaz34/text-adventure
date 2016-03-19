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
	Item* m_Equiptment[1];
	//std::vector<Item*> m_Equiptment;
public:
	Inventory();
	~Inventory();
	void addWeapon(String name, weaponType wepType, ElementalDamage element, int damage);
	void addPotion(String name, int stack);

	void equipItem(String itemName)
	{
		m_ItemList.push_back(m_Equiptment[0]);
		m_Equiptment[0] = getItem(itemName);
		m_ItemList.erase(m_ItemList.begin() + getItemIndex(itemName));

	};
	Item* getItem(int itemNameID) {
		if (itemNameID >= 0 && itemNameID <= m_ItemList.size())
		{
			return m_ItemList[itemNameID];
		}
		return nullptr;
	}
	Item* getItem(String itemName) {
		for (Item* item : m_ItemList) {
			if (item->getName() == itemName)
			{
				return item;
			}
		}
		return nullptr;
	}
	int getItemIndex(String itemName) {
		int counter = 0;
		for (Item* item : m_ItemList) {
			if (item->getName() == itemName)
			{
				return counter;
			}
			else {
				counter++;
			}
		}
		return -1;
	}
	Item* getEquipItem(int index) {
		return m_Equiptment[index];
	}
};

