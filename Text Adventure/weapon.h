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
struct damageInfo
{
	int damage;
	ElementalDamage element;
	weaponType wepType;
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
		m_damage = damage;
	};
	virtual void use(Character* target);
	~Weapon();

};

