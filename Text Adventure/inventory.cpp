#include "inventory.h"

Inventory::Inventory()
{
	m_Equiptment[5] = new Weapon("fist", weaponType::MELEE, ElementalDamage::PHYSICAL, 1);
	m_Equiptment[0] = new Armor("a sick haircut", 0, {}, armorType::HEAD);
	m_Equiptment[1] = new Armor("tattered shirt", 1, {}, armorType::CHEST);
	m_Equiptment[2] = new Armor("your bare skin", 0, {}, armorType::ARMS);
	m_Equiptment[3] = new Armor("tattered pants", 1, {}, armorType::LEGS);
	m_Equiptment[4] = new Armor("tattered shoes", 1, {}, armorType::FEET);
}

Inventory::~Inventory()
{
	
}

void Inventory::addWeapon(String name, weaponType wepType, ElementalDamage element, int damage)
{
	bool Collected = false;
	for (Item* item : m_ItemList)
	{
		if (item->getName() == name)
		{
			Collected = true;
			break;
		}
	}
	if (!Collected)
	{
		m_ItemList.push_back(new Weapon(name, wepType, element, damage));
	}
	else
	{
		std::cout << "already have that weapon, no need for 2 that is just greedy!\n";
	}
}

void Inventory::equipItem(String itemName)
{
	int type = getItem(itemName)->getType();
	m_ItemList.push_back(m_Equiptment[type]);
	m_Equiptment[type] = getItem(itemName);
	m_ItemList.erase(m_ItemList.begin() + getItemIndex(itemName));
}

Item * Inventory::getItem(int itemNameID)
{
	if (itemNameID >= 0 && itemNameID <= m_ItemList.size())
	{
		return m_ItemList[itemNameID];
	}
	return nullptr;
}

Item * Inventory::getItem(String itemName)
{
	for (Item* item : m_ItemList) {
		if (item->getName() == itemName)
		{
			return item;
		}
	}
	return nullptr;
}

int Inventory::getItemIndex(String itemName)
{
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
