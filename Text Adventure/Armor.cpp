#include "Armor.h"



Armor::Armor(String name, int armor, resistanceList resistances, armorType type) : Item(name, (int)type)
{
	m_info.m_armor = armor;
	
	for (ElementalDamage resistance : resistances) {
		m_info.m_resistances.push_back(resistance);
	}
}

defenseInfo Armor::getInfo()
{
	return m_info;
}

void Armor::use(Character * target)
{
}


Armor::~Armor()
{
}
