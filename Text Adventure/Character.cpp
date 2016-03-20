#include "Character.h"

void Character::changeHealth(damageInfo dInfo)
{
	bool resistant = false;
	int armor = 0;
	defenseInfo defenceValues[5];
	for (int i = 0; i < 5; i++)
	{
		defenceValues[i] = m_inventory.getEquipItem(i)->getInfo();
		armor += defenceValues[i].m_armor;
	}
	for (ElementalDamage element : defenceValues[1].m_resistances) {
		if (element == dInfo.m_element)
		{
			resistant = true;
			break;
		}
	}
	float damageReduction = (float)100 / (100 + armor);
	if (resistant == true)
	{
		m_health -= int(dInfo.m_damage * damageReduction / 2);
	}
	else {
		m_health -= int(dInfo.m_damage * damageReduction);
	}
}

void Character::attack(Character & target)
{
	m_inventory.getEquipItem(5)->use(&target);
}

Character::Character(int health, String name)
{
	m_health = health;
	m_name = name;
}

Character::~Character()
{

}

