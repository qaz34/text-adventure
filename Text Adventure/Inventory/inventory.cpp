#include "Inventory.h"

Inventory::Inventory()
{
	m_Equiptment[0] = new Armor("a sick haircut", armorType::HEAD, { 1,{} });
	m_Equiptment[1] = new Armor("tattered shirt", armorType::CHEST, { 2,{} });
	m_Equiptment[2] = new Armor("bare skin", armorType::ARMS, { 1,{} });
	m_Equiptment[3] = new Armor("tattered pants", armorType::LEGS, { 2,{} });
	m_Equiptment[4] = new Armor("tattered shoes", armorType::FEET, { 2,{} });
	m_Equiptment[5] = new Weapon("fist", weaponType::MELEE, ElementalDamage::PHYSICAL, 5);
}

Inventory::~Inventory()
{
	for (Item* item : m_ItemList)
	{
		delete item;
	}
	for (int i = 0; i < 6; ++i) {
		delete m_Equiptment[i];
	}
}

void Inventory::addWeapon(String name, weaponType wepType, ElementalDamage element, int damage)
{
	bool Collected = false;
	bool Redone = false;
	for (Item* item : m_ItemList)
	{
		if (item->getName() == name || m_Equiptment[5]->getName() == name)
		{
			if (item->getInfo().m_armor != damage && item->getName() == name)
			{
				deleteItem(name);
				break;
			}
			else if (item->getInfo().m_armor != damage && m_Equiptment[5]->getName() == name) {
				m_ItemList.push_back(new Weapon(name, wepType, element, damage));
				equipItem(name);
				deleteItem(name);
				Redone = true;
				break;
			}
			else {
				Collected = true;
				break;
			}
		}
	}
	if (!Collected && !Redone)
	{
		m_ItemList.push_back(new Weapon(name, wepType, element, damage));
	}
	else if (Redone) {
		std::cout << "Weapon upgraded\n";
	}
	else
	{
		std::cout << "already have that weapon, no need for 2 that is just greedy!\n";
	}
}

void Inventory::addWeapon(Item* item)
{
	bool Collected = false;
	bool Redone = false;
	for (Item* items : m_ItemList)
	{
		if (items->getName() == item->getName() || m_Equiptment[5]->getName() == item->getName())
		{
			if (items->getInfo().m_armor != item->getInfo().m_armor && items->getName() == item->getName())
			{
				deleteItem(items->getName());
				break;
			}
			else if (items->getInfo().m_armor != item->getInfo().m_armor && m_Equiptment[5]->getName() == item->getName()) {
				m_ItemList.push_back(new Weapon(item->getName(), (weaponType)item->getInfo().m_resistances[1], item->getInfo().m_resistances[0], item->getInfo().m_armor));
				equipItem(item->getName());
				deleteItem(item->getName());
				Redone = true;
				break;
			}
			else {
				Collected = true;
				break;
			}
		}
	}

	if (!Collected && !Redone)
	{
		m_ItemList.push_back(new Weapon(item->getName(), (weaponType)item->getInfo().m_resistances[1], item->getInfo().m_resistances[0], item->getInfo().m_armor));
	}
	else if (Redone) {
		std::cout << "Weapon upgraded\n";
	}
	else
	{
		std::cout << "already have that weapon, no need for 2 that is just greedy!\n";
	}
}

void Inventory::addItem(Item & item)
{
	if (item.getType() <= 4) {
		addArmor(&item);
	}
	else if(item.getType() == 5){
		addWeapon(&item);
	}
	else if (item.getType() == 6) {
		addHeaingPotion(&item);
	}
}

void Inventory::addHeaingPotion(String name, int stack, int healing)
{
	bool collected = false;
	for (Item* item : m_ItemList) {
		if (item->getName() == name) {
			item->addStack(stack);
			collected = true;
		}
	}
	if (!collected) {
		m_ItemList.push_back(new HealingPotion(name, stack, healing));
	}
}
void Inventory::addHeaingPotion(Item* item)
{
	bool collected = false;
	for (Item* items : m_ItemList) {
		if (items->getName() == item->getName()) {
			items->addStack(1);
			collected = true;
		}
	}
	if (!collected) {
		m_ItemList.push_back(new HealingPotion(item->getName(), 1, item->getInfo().m_armor));
	}
}
void Inventory::addArmor(String name, armorType armType, defenseInfo dInfo)
{
	bool Collected = false;
	bool Redone = false;
	for (Item* item : m_ItemList)
	{
		for (size_t i = 0; i < 5; i++)
		{
			if (item->getName() == name || m_Equiptment[i]->getName() == item->getName())
			{
				if (item->getInfo().m_armor != dInfo.m_armor)
				{
					deleteItem(name);
					break;
				}
				else if (m_Equiptment[i]->getInfo().m_armor != dInfo.m_armor) {
					m_ItemList.push_back(new Armor(name, armType, dInfo));
					equipItem(name);
					deleteItem(name);
					Redone = true;
					break;
				}
				else {
					Collected = true;
					break;
				}

			}
		}
	}

	if (!Collected && !Redone)
	{
		m_ItemList.push_back(new Armor(name, armType, dInfo));
	}
	else if (Redone) {
		std::cout << "Armor upgraded\n";
	}
	else {
		std::cout << "already have that Armor, no need for 2 that is just greedy!\n";
	}
}


void Inventory::addArmor(Item * item)
{
	bool Collected = false;
	bool Redone = false;
	bool BREAK = false;
	for (Item* items : m_ItemList)
	{
		for (size_t i = 0; i < 5; i++)
		{
			if (item->getName() == items->getName() || m_Equiptment[i]->getName() == item->getName())
			{
				if (item->getInfo().m_armor != items->getInfo().m_armor && items->getName() == item->getName())
				{
					deleteItem(item->getName());
					BREAK = true;
					break;
				}
				else if (item->getInfo().m_armor != m_Equiptment[i]->getInfo().m_armor && m_Equiptment[i]->getName() == item->getName()) {
					m_ItemList.push_back(new Armor(item->getName(), (armorType)item->getType(), item->getInfo()));
					equipItem(item->getName());
					deleteItem(item->getName());
					
					Redone = true;
					BREAK = true;
					break;
				}
				else {
					Collected = true;
					BREAK = true;
					break;
				}

			}
			
		}
		if (BREAK) {
			break;
		}
	}

	if (!Collected && !Redone)
	{
		m_ItemList.push_back(new Armor(item->getName(), (armorType)item->getType(), item->getInfo()));
	}
	else if (Redone) {
		std::cout << "Armor upgraded\n";
	}
	else {
		std::cout << "already have that Armor, no need for 2 that is just greedy!\n";
	}

}

void Inventory::equipItem(String itemName)
{
	int type = getItem(itemName)->getType();
	m_ItemList.push_back(m_Equiptment[type]);
	m_Equiptment[type] = getItem(itemName);
	m_ItemList.erase(m_ItemList.begin() + getItemIndex(itemName));
}
void Inventory::deleteItem(String Name) {
	m_ItemList.erase(m_ItemList.begin() + getItemIndex(Name));
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
