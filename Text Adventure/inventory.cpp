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
//void inventory::addpotion(string name, int stack)
//{
//	bool collected = false;
//	items* tempitem;
//	for (items* item : m_itemlist)
//	{
//		if (item->getname() == name)
//		{
//			collected = true;
//			tempitem = item;
//			break;
//		}
//	}
//	if (!collected)
//	{
//		m_itemlist.push_back(new potion(name, stack));
//	}
//	else
//	{
//		tempitem->changepotionstack(stack);
//	}
//}
