#pragma once
#include "strings.h"

class Character;
class Item
{
protected:
	String m_name;
public:
	Item(String name) {
		m_name = name;
	}
	~Item();
	virtual void use(Character*) = 0;
};

