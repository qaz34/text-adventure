#include "Character.h"

void Character::changeHealth(damageInfo dInfo)
{
	bool resistant = false;
	for (ElementalDamage element : m_resistances) {
		if (element == dInfo.element)
		{
			resistant = true;
			break;
		}
	}
	if (resistant == true)
	{
		m_health -= dInfo.damage * m_damageReduction / 2;
	}
	else {
		m_health -= dInfo.damage * m_damageReduction;
	}
}

void Character::attack(Character & target)
{
	m_inventory.getEquipItem(0)->use(&target);
}

Character::Character(int health, int armor, String name, resistanceList resistances)
{
	m_health = health;
	m_armor = armor;
	m_name = name;
	m_damageReduction = ((float)100 / (100 + armor));
	m_inventory.addWeapon("crappy sword", weaponType::MELEE, ElementalDamage::PHYSICAL, 2);
	m_inventory.equipItem("crappy sword");
	for (ElementalDamage resistance : resistances) {
		m_resistances.push_back(resistance);
	}
	
}

Character::~Character()
{
}

