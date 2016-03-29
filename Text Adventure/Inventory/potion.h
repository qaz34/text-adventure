#pragma once
#include "items.h"
#include "../String/Strings.h"
class Potion : public Item
{
protected:
	int m_stack;
public:
	Potion(String name, int stack) : Item(name,6) {
		m_stack = stack;
	};
	virtual void use(Character &target) = 0;
	virtual defenseInfo getInfo() = 0;
	virtual void addStack(int ammount) = 0;
	~Potion() {}
};

