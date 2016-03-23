#include "Weapon.h"
#include "../Character.h"
Weapon::~Weapon()
{
}

void Weapon::use(Character& target) {
	if (weaponType::RANGED == m_info.m_wepType) {
		for (int i = 0; i < random(1, 5); ++i) {
			target.changeHealth(m_info);
		}
	}else if (weaponType::MAGIC == m_info.m_wepType) {
		target.changeHealth(m_info);
		target.changeHealth(m_info);
	}
	else {
		target.changeHealth(m_info);
	}
	
}