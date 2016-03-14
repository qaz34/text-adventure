#pragma once
#include "items.h"
#include "strings.h"
enum class weaponType
{
	MELEE,
	RANGED,
	MAGIC
};
enum class ElementalDamage
{
	PHYSICAL,
	WIND,
	FIRE,
	WATER,
	EARTH
};
class Weapon : public Item
{
protected:
	weaponType m_type;
	ElementalDamage m_element;
	int m_damage;
public:
	Weapon(String name, weaponType wepType, ElementalDamage element, int damage) : Item(name) {
		m_type = wepType;
		m_element = element;
		m_damage = 10;
	};
	virtual void use(Character* target);
	~Weapon();

};

