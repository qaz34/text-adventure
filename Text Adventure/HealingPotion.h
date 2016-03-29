#pragma once
#include "String\Strings.h"
#include"Inventory\Potion.h"
class Character;
class HealingPotion : public Potion
{
protected:
	int m_healingEffect;
public:
	HealingPotion(String Name, int stack, int healing);
	virtual void use(Character &target);
	virtual defenseInfo getInfo() {
		defenseInfo temp;
		temp.m_armor = m_healingEffect;
		temp.m_resistances = {};
		return temp;
	};
	void addStack(int ammount) {
		m_stack += ammount;
	}

	~HealingPotion();
};

