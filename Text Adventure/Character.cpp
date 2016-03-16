#include "Character.h"

void Character::changeHealth(int ammount)
{
	m_health += ammount;
}

Character::Character(int health, int armor, String name )
{
	m_name = name;
	m_health = health;
	m_armor = armor;
	m_armorReduction = (float)armor / (armor + 50);
}

Character::Character(int health, int armor, String name, std::vector<ElementalDamage> resistances)
{
	m_name = name;
	m_health = health;
	m_armor = armor;
	m_armorReduction = (float)armor / (armor + 50);
	int i = 0;
	for (ElementalDamage element : resistances) {
		m_resistances.push_back(new ElementalDamage(element));
		i++;
	}
}

Character::~Character()
{
}

