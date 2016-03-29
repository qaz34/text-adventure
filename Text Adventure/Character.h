#pragma once
#include "String\Strings.h"
#include "Inventory/Inventory.h"
#include <cmath>
#include <iostream>
const float constantLvl = 0.35f;

typedef std::vector<ElementalDamage> resistanceList;
class Character
{
protected:
	String m_name;
	float m_constantHealth;
	int m_health, m_maxHealth, m_level, m_exp;
	Inventory m_inventory;
	
public:
	int m_x, m_y;
	void addWeapon(String name, weaponType wepType, ElementalDamage element, int damage) {
		m_inventory.addWeapon(name, wepType, element, damage);
	}
	void addArmor(String name, armorType armType, defenseInfo dInfo) {
		m_inventory.addArmor(name, armType, dInfo);
	}
	void addHealthPotion(String name, int stack, int healing) {
		m_inventory.addHeaingPotion(name, stack, healing);
	}
	void addItem(Item& items) {
		m_inventory.addItem(items);
	}
	void equipItem(String name) {
		if (m_inventory.getItem(name) != nullptr)
		{
			m_inventory.equipItem(name);
		}
	}
	void usePotion(Character & target, String name);
	int health() { return m_health; }
	String itemName(int index) { return m_inventory.getItem(index)->getName(); }
	int invetorySize() { return m_inventory.size(); }
	bool isDead() { return m_health == 0; }
	void changeHealth(damageInfo& dInfo);
	void attack(Character& target);
	Item* getEquippedItem(int index) { return m_inventory.getEquipItem(index); }
	String name() { return m_name; }
	int getLevel() { return m_level; }
	void Heal(int ammount) {
		if (m_health + ammount < m_maxHealth) {
			m_health += ammount;
			std::cout << "You drank the potion and healed " << ammount << " health\n";
		}
		else if(m_health == m_maxHealth){
			std::cout << "You drank the potion, it did nothing\n";
		}
		else if (m_health + ammount >= m_maxHealth) {
			m_health = m_maxHealth;
			std::cout << "You drank the potion and healed to max health\n";
		}
	}
	Character(int health, String name);
	Character(int health, String name, int level);
	void displayInventory() {
		m_inventory.displayInventory();
	}
	void displayEquipment() {
		m_inventory.displayEquipment();
	}
	void gainExp(int exp);
	/*level = constant * sqrt(XP)*/
	~Character();

};
