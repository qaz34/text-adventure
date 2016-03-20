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
	m_inventory.getEquipItem(5)->use(target);
}

Character::Character(int health, String name)
{
	m_health = health;
	m_name = name;
}

Character::Character(int health, String name, int exp) : Character(health, name)
{
	m_exp = exp;
	m_level = floor(constantLvl * sqrt(m_exp));
	m_constantHealth = m_level / sqrt(m_health);
}

void Character::gainExp(int exp)
{
	m_exp += exp;
	int newLevel = floor(constantLvl * sqrt(exp));
	if (m_level <= newLevel)
	{
		m_health = floor(pow(newLevel / m_constantHealth, 2));
	}
	else if (newLevel == 0) {
		m_level = 1;
		m_health = floor(pow(m_level / m_constantHealth, 2));

	}
}

Character::~Character()
{

}

