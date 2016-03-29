#include "HealingPotion.h"
#include "Character.h"
HealingPotion::HealingPotion(String name, int stack, int healing) : Potion(name, stack)
{
	m_healingEffect = healing;
}

void HealingPotion::use(Character & target)
{
	if (m_stack > 0) {
		target.Heal(m_healingEffect);
		m_stack--;
	}
	else {
		std::cout << "You dont have any of those\n";
	}
}

HealingPotion::~HealingPotion()
{
}
