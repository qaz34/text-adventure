#include "Character.h"

void Character::changeHealth(int ammount)
{
	m_health += ammount;
}

Character::Character(int health, String name)
{
	m_name = name;
	m_health = health;
}

Character::~Character()
{
}

