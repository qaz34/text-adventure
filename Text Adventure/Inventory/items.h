#pragma once
#include "../String/Strings.h"
#include <vector>

enum class ElementalDamage
{
	PHYSICAL,
	WIND,
	FIRE,
	WATER,
	EARTH
};
typedef std::vector<ElementalDamage> resistanceList;
struct defenseInfo {
	int m_armor;
	resistanceList m_resistances;
};
class Character;
class Item
{
protected:
	String m_name;
	int m_type;
public:
	Item(String name, int type) {
		m_name = name;
		m_type = type;
	}
	~Item();
	String getName() { return m_name; };
	virtual void use(Character &target) = 0;
	virtual defenseInfo getInfo() = 0;
	virtual void addStack(int ammount) = 0;
	int getType() { return m_type; }

};

