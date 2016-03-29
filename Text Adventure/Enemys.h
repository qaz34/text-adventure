#pragma once
#include "String\Strings.h"

class Enemys
{
	String Names[10], Prepends[5];
public:
	int random(int min, int max) {

		return rand() % (max - min + 1) + min;
	}
	Enemys() {
		Names[0] = "Dude";
		Names[1] = "Slime";
		Names[2] = "Shade";
		Names[3] = "Wolf";
		Names[4] = "BirdMan";
		Names[5] = "Ogre";
		Names[6] = "Elf";
		Names[7] = "Vampire";
		Names[8] = "Dragon";
		Names[9] = "Goblin";

		Prepends[0] = "Evil";
		Prepends[1] = "Dark";
		Prepends[2] = "Ice";
		Prepends[3] = "Dire";
		Prepends[4] = "Super";
	}
	String returnName(){
		String fullName;
		fullName = Prepends[random(0,4)] + " " + Names[random(0, 9)];
		return fullName;
	}
};

