// Text Adventure.cpp : Defines the entry point for the console application.
//
#include "Character.h"
#include "String/Strings.h"
#include <iostream>
#include <chrono>
using namespace std;
typedef vector<Character*> targets;
int random(int min, int max) {
	return rand() % max + min;
}
void gameover() {
	cout << "you died" << endl;
}
void battleRound(Character& Player, Character& target)
{
	cout << Player.name() << " attacked " << target.name() << endl;
	Player.attack(target);
	if (!target.isDead())
	{
		cout << target.name() << " has " << target.health() << " health left" << endl;
		target.attack(Player);
		cout << Player.name() << " has " << Player.health() << " health left" << endl;
		if (Player.isDead()) {
			gameover();
		}
	}
	else {
		cout << target.name() << " died" << endl;
		int randomNum = random(0,5);
		cout << target.name() << " dropped " << target.getEquippedItem(randomNum)->getName() << endl;
		String input;
		input.getline();
		if (input.toLower().subStringFind("pickup") != nullptr)
		{
			Player.addItem(*target.getEquippedItem(randomNum));
		}
		else if (input.toLower().subStringFind("leave") != nullptr)
		{

		}
		else {
			cout << "not an option" << endl;
		}
		Player.gainExp(target.getLevel());

	}
}
void command(String input, targets& targetList, Character& Player) {
	if (input.toLower().subStringFind("attack") != nullptr)
	{
		int counter = 0;
		for (Character* target : targetList) {
			if (input.toLower().subStringFind(target->name().toLower()) != nullptr)
			{
				battleRound(Player, *target);
				if (target->isDead()) {
					targetList.erase(targetList.begin() + counter);
				}
				break;
			}
			counter++;
		}
		if (counter == targetList.size() - 1) {
			cout << "Not a target" << endl;
		}
	}
	else if (input.toLower().subStringFind("equip") != nullptr)
	{

		for (int i = 0; i < Player.invetorySize(); ++i) {
			if (input.toLower().subStringFind(Player.itemName(i), 6) != nullptr) {
				Player.equipItem(input.toLower().subStringFind(Player.itemName(i), 6));
			}
		}
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
	cout << "input name: ";
	Character player(100, Input.Returnline());
	targetList.push_back(&player);
	player.addWeapon("sword", weaponType::MELEE, ElementalDamage::PHYSICAL, 5);
	targetList.push_back(new Character(20, "evil dude", 2));
	targetList[1]->addWeapon("evil sword", weaponType::MELEE, ElementalDamage::PHYSICAL, 25);
	targetList[1]->equipItem("evil sword");
	while (true)
	{
		cout << "input command\n";
		command(Input.Returnline(), targetList, player);
	}
	return 0;
}