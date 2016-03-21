#include "Armor.h"



Armor::Armor(String name, armorType type, defenseInfo dInfo) : Item(name, (int)type)
{
	m_info.m_armor = dInfo.m_armor;
	
	for (ElementalDamage resistance : dInfo.m_resistances) {
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
