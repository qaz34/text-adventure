// Text Adventure.cpp : Defines the entry point for the console application.
//
#include "Player.h"
#include "strings.h"
#include <iostream>
using namespace std;
void quickTest(ElementalDamage * test) {

}
int main()
{
	String testString;
	Character player(10, testString.Returnline());
	Character enemy(1000, "jeffers the vile", 5103);
	while (true)
	{
		player.addWeapon("basic sword", weaponType::MELEE, ElementalDamage::PHYSICAL, 10);
		player.equipItem("basic sword");
		player.addArmor("helm of jeffry", armorType::HEAD, { 3, {} });
		player.equipItem("helm of jeffry");
		player.addArmor("chest piece of jeffry", armorType::CHEST, { 2,{ElementalDamage::PHYSICAL} });
		player.equipItem("chest piece of jeffry");
		player.attack(player);
		system("PAUSE");
	}
	return 0;
}