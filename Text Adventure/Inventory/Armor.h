#pragma once
#include "Items.h"
#include "../String/Strings.h"

enum class armorType
{
	HEAD,
	CHEST,
	ARMS,
	LEGS,
	FEET
};


class Armor : public Item
{
protected:
	defenseInfo m_info;
public:
	Armor(String name, armorType type, defenseInfo dInfo);
	defenseInfo getInfo();
	void use(Character& target);
	void addStack(int ammount) {}
	~Armor();
};

