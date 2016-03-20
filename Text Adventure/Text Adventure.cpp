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
	while (true)
	{
		player.addWeapon("basic sword", weaponType::MELEE, ElementalDamage::PHYSICAL, 1000);
		player.equipItem("basic sword");
		player.attack(player);
		system("PAUSE");
	}
    return 0;
}