// Text Adventure.cpp : Defines the entry point for the console application.
//
#include "Character.h"
#include "Strings.h"
#include <iostream>
using namespace std;
int main()
{

	String testString;
	Character player(10, testString.Returnline());
	Character enemy(1000, "jeffers the vile", 5103);
	while (true)
	{
		player.addWeapon("super sword of jeffry", weaponType::MELEE, ElementalDamage::PHYSICAL, 10000);
		player.equipItem("basic sword");
		player.addArmor("helm of jeffry", armorType::HEAD, { 3, {} });
		player.equipItem("helm of jeffry");
		player.addArmor("chest piece of jeffry", armorType::CHEST, { 2,{ElementalDamage::PHYSICAL} });
		player.equipItem("chest piece of jeffry");
		player.addArmor("boots of jeffry", armorType::FEET, { 50,{ ElementalDamage::PHYSICAL, ElementalDamage::EARTH, ElementalDamage::FIRE, ElementalDamage::WATER, ElementalDamage::WATER } });
		enemy.addWeapon("enemy wand", weaponType::MAGIC, ElementalDamage::WIND, 10);
		enemy.equipItem("enemy wand");
		enemy.attack(player);
		player.attack(enemy); 
		

		if (enemy.isDead()) {
			player.gainExp(pow(enemy.getLevel(),2));
		}
		system("PAUSE");
	}
	return 0;
}