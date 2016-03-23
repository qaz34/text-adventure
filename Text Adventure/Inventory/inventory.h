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
	String tabbing(String string) {
		String tabs(string);
		if (string.Length() < 8)
		{
			tabs += "\t\t\t";
		}
		else if (string.Length() < 16) {
			tabs += "\t\t";
		}
		else if (string.Length() < 32) {
			tabs += "\t";
		}
		return tabs;
	}

	void addWeapon(String name, weaponType wepType, ElementalDamage element, int damage);
	void addWeapon(Item* item);
	void addItem(Item& item);
	void addArmor(String name, armorType armType, defenseInfo dInfo);
	void addArmor(Item* item);
	void equipItem(String itemName);
	int size() { return (int)m_ItemList.size(); }
	Item* getItem(int itemNameID);
	Item* getItem(String itemName);
	void displayInventory() {
		std::cout << "Name\t\t\tStat\tElements\n";
		for (Item* item : m_ItemList) {
			std::cout << tabbing(item->getName()) << item->getInfo().m_armor  << '\t'  << item->getInfo().m_resistances.size()<<  '\n';
		}
	}
	void displayEquipment() {
		std::cout << "Name\t\t\tStat\tElements\n";
		for (int i = 0; i < 6; ++i) {
			std::cout << tabbing(m_Equiptment[i]->getName()) << m_Equiptment[i]->getInfo().m_armor << '\t' << m_Equiptment[i]->getInfo().m_resistances.size() << '\n';
		}
	}
	int getItemIndex(String itemName);
	Item* getEquipItem(int index) { return m_Equiptment[index]; }
};

