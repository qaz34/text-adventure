#include "inventory.h"



Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}

void Inventory::addWeapon(String name, weaponType wepType, ElementalDamage element, int damage)
{
	bool Collected = false;
	/*for (items* item : m_ItemList)
	{
		if (item->getName() == name && item->getDamage() == damage)
		{
			Collected = true;
			break;
		}
	}*/
	if (!Collected)
	{
		m_ItemList.push_back(new Weapon(name, wepType, element, damage));
	}
	else
	{
		std::cout << "already have that weapon, no need for 2 that is just greedy!\n";
	}
}
//void inventory::addPotion(String name, int stack)
//{
//	bool Collected = false;
//	items* tempItem;
//	for (items* item : m_ItemList)
//	{
//		if (item->getName() == name)
//		{
//			Collected = true;
//			tempItem = item;
//			break;
//		}
//	}
//	if (!Collected)
//	{
//		m_ItemList.push_back(new potion(name, stack));
//	}
//	else
//	{
//		tempItem->changePotionStack(stack);
//	}
//}
