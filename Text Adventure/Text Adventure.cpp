// Text Adventure.cpp : Defines the entry point for the console application.
//
#include "Character.h"
#include "Strings.h"
#include <iostream>
#include <chrono>
using namespace std;
typedef vector<Character> targets;
void command(String input, targets targetList, Character Player) {
	if (input.toLower().subStringFind("attack") != nullptr)
	{
		int counter = 0;
		for (Character target : targetList) {
			if (input.toLower().subStringFind(target.name()))
			{
				Player.attack(target);
				break;
			}
			counter++;
		}
		if (counter == targetList.size()) {
			cout << "Not a target" << endl;
		}
	}
	else if (input.toLower().subStringFind("equip") != nullptr)
	{

	}
	else if (input.toLower().subStringFind("use") != nullptr)
	{

	}
	else if (input.toLower().subStringFind("move") != nullptr)
	{

	}
	else if (input.toLower().subStringFind("pickup") != nullptr)
	{

	}
}
int main()
{
	targets targetList;

	srand(time(NULL));
	String Input;
	Character player(10, Input.Returnline());
	targetList.push_back(player);
	while (true)
	{
		command(Input.Returnline(), targetList, player);
		system("PAUSE");
	}
	return 0;
}