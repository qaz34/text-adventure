// Text Adventure.cpp : Defines the entry point for the console application.
//
#include "Character.h"
#include "strings.h"
#include <iostream>
using namespace std;
int main()
{
	String input;
	Character player(100, 10, input.Returnline(), {ElementalDamage::PHYSICAL,ElementalDamage::FIRE});
	while (true)
	{
		player.addWeapon("basic sword", weaponType::MELEE, ElementalDamage::PHYSICAL, 10);
		player.m_inventory.getItem(0)->use(player);
		system("PAUSE");
	}
    return 0;
}

