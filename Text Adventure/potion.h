#pragma once
#include "items.h"
#include "strings.h"
class Potion : public Item
{
protected:
	int m_stack;
	int m_healing;
public:
	Potion(String name, int stack) : Item(name) {
		m_stack = stack;
	};
	Potion();
	~Potion();
	virtual void usePotion() {
		if (m_stack > 0)
		{
			m_stack--;
			m_healing++;
		}
		else {

		}

	}

};

