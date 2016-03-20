#include "weapon.h"
#include "Character.h"
Weapon::~Weapon()
{
}

<<<<<<< HEAD
void Weapon::use(Character & target) {
	target.takeDamage(m_damage, m_element);
=======
void Weapon::use(Character* target) {
	target->changeHealth(m_info);
>>>>>>> 05060c54971128f9c677e9e8aa979ff579eb98dd
}