#include "weapon.h"
#include "Character.h"
Weapon::~Weapon()
{
}

void Weapon::use(Character & target) {
	target.takeDamage(m_damage, m_element);
}