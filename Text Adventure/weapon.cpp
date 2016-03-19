#include "weapon.h"
#include "Character.h"
Weapon::~Weapon()
{
}

void Weapon::use(Character* target) {
	target->changeHealth({m_damage, m_element, m_type});
}