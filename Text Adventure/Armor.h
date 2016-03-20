#pragma once
#include "items.h"
#include "strings.h"

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
	virtual defenseInfo getInfo();
	virtual void use(Character& target);
	~Armor();
};

