#include "Character.h"



void Character::changeHealth(damageInfo& dInfo)
{
	int resistant = 0;
	int armor = 0;
	defenseInfo defenceValues[5];
	for (int i = 0; i < 5; i++)
	{
		defenceValues[i] = m_inventory.getEquipItem(i)->getInfo();
		armor += defenceValues[i].m_armor;
		for (ElementalDamage element : defenceValues[i].m_resistances) {
			if (element == dInfo.m_element)
			{
				resistant++;
				break;
			}
		}
	}
	float damageReduction = (float)100 / (100 + armor);
	m_health -= int(dInfo.m_damage * damageReduction * ((float)15 / (float)(15 + resistant)));
	if (m_health <= 0) {
		m_health = 0;
	}
}

void Character::attack(Character & target)
{
	m_inventory.getEquipItem(5)->use(target);
}

void Character::usePotion(Character & target, String name)
{
	m_inventory.getItem(name)->use(target);
}
Character::Character(int health, String name)
{
	m_health = m_maxHealth = health;
	m_name = name;
	m_level = 1;
	m_x = m_y = 0;
	m_exp = 10;
	m_constantHealth = m_level / sqrt(m_health);
}

Character::Character(int health, String name, int level) : Character(health, name)
{
	m_exp = pow(level/constantLvl,2);
	m_level = level;
	m_constantHealth = m_level / sqrt(m_health);
}

void Character::gainExp(int enemyLevel)
{
	m_exp += pow(enemyLevel,2);
	int newLevel = floor(constantLvl * sqrt(m_exp));
	if (m_level < newLevel)
	{
		m_maxHealth = m_health = floor(pow(newLevel / m_constantHealth, 2));
		std::cout << "Level up! you are now level " << newLevel << " and have a max health of " << m_maxHealth << std::endl;
		m_level = newLevel;
	}
	else if (newLevel == 0) {
		m_level = 1;
		m_maxHealth = m_health = floor(pow(m_level / m_constantHealth, 2));
	}
}

Character::~Character()
{

}

