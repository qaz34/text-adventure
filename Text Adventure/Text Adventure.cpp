// Text Adventure.cpp : Defines the entry point for the console application.
//
#include "Player.h"
#include "strings.h"
#include <iostream>
using namespace std;
int main()
{
	String testString;
	Character player(100, testString.Returnline());
	while (true)
	{
		player.addWeapon("basic sword", weaponType::MELEE, ElementalDamage::PHYSICAL, 10);
		system("PAUSE");
	}
    return 0;
}

