// Text Adventure.cpp : Defines the entry point for the console application.
//
#include "Character.h"
#include "String/Strings.h"
#include "ItemList.h"
#include "Inventory\Weapon.h"
#include <iostream>
#include <chrono>
#include "Enemys.h"
#include <cmath>
using namespace std;
typedef vector<Character*> targets;
bool playing;
Enemys enemyName;
int random(int min, int max) {

	return rand() % (max - min + 1) + min;
}
void gameover() {
	cout << "you died" << endl;
	playing = false;
}
void deleteCharacter(targets& targetList, Character& target) {
	int counter = 0;
	for (Character* enemy : targetList) {
		if (enemy->name() == target.name()) {
			targetList.erase(targetList.begin() + counter);
			break;
		}
		else
		{
			counter++;
		}
	}
}
void battleRound(Character& Player, Character& target, targets& targetList)
{
	cout << Player.name() << " attacked " << target.name() << endl;
	Player.attack(target);
	if (!target.isDead())
	{
		cout << target.name() << " has " << target.health() << " health left" << endl;
	}
	else {

		cout << target.name() << " died" << endl;
		int randomNum = random(0, 9);
		if (randomNum > 5) {
			randomNum = 5;
		}
		Player.gainExp(target.getLevel());
		cout << target.name() << " dropped " << target.getEquippedItem(randomNum)->getName() << endl;
		String input;
		while (true) {
			input.getline();
			if (input.toLower().subStringFind("pickup") != nullptr)
			{
				Player.addItem(*target.getEquippedItem(randomNum));
				deleteCharacter(targetList, target);
				break;

			}
			else if (input.toLower().subStringFind("leave") != nullptr)
			{
				deleteCharacter(targetList, target);
				break;
			}
			else {
				cout << "not an option" << endl;
			}
		}
		randomNum = random(0, 2);
		if (randomNum = 1) {
			ItemList temp;
			randomNum = random(0, 6);
			String name = temp.getItem(6, randomNum)->getName();
			cout << target.name() << " dropped " << name << endl;
			while (true) {
				input.getline();
				if (input.toLower().subStringFind("pickup") != nullptr)
				{
					Player.addItem(*temp.getItem(6, randomNum));
					break;

				}
				else if (input.toLower().subStringFind("leave") != nullptr)
				{
					break;
				}
				else {
					cout << "not an option" << endl;
				}
			}
		}
	}
	int i = 0;
	if (targetList.size() > 1) {
		for (Character* enemy : targetList) {
			if (i >= 1) {
				cout << enemy->name() << " attacked " << Player.name() << "\n";
				enemy->attack(Player);
				cout << Player.name() << " has " << Player.health() << " health left" << endl;
				if (Player.isDead()) {
					gameover();
				}
			}
			else {
				++i;
			}
		}
	}
}
void rollItems(Character& character) {
	ItemList ItemList(character.getLevel());
	for (size_t i = 0; i < 6; i++)
	{
		Item* item = ItemList.getItem(i, random(0, 6));
		character.addItem(*item);
		character.equipItem(item->getName());
	}
}
void testForEvent(targets& targetList) {
	bool encounter = true;
	
	if (targetList[0]->m_x == 0 && targetList[0]->m_y == 0) {
		cout << "A random place\n";
	}else if (targetList[0]->m_x == 0 && targetList[0]->m_y == 1) {
		cout << "here lies my sanity\n";
	}
	else {
		encounter = false;
		for (size_t i = 0; i < 4; i++)
		{
			int randomNum = random(0, 20);
			if (randomNum <= 7) {
				String enemysName = enemyName.returnName();
				encounter = true;
				bool nameDone = false;
				while (nameDone == false)
				{
					nameDone = true;
					for (Character* enemy : targetList) {
						if (enemysName == enemy->name())
						{
							enemysName = enemyName.returnName();
							nameDone = false;
						}
					}
				}
				targetList.push_back(new Character(pow(targetList[0]->getLevel() / .5, 2), enemysName, targetList[0]->getLevel() + 1));
				rollItems(*targetList[targetList.size() - 1]);
				cout << targetList[targetList.size() - 1]->name() << " appeared\n";
			}
			else {
				break;
			}
		}
	}
	if(!encounter){
		cout << "Nothing interesting\n";
	}
}
void command(String input, targets& targetList, Character& Player) {
	if (input.toLower().subStringFind("attack") != nullptr)
	{
		bool Targeted = false;
		for (Character* target : targetList) {
			if (input.toLower().subStringFind(target->name().toLower()) != nullptr)
			{
				battleRound(Player, *target, targetList);
				Targeted = true;
				break;
			}
		}
		if (Targeted == false) {
			cout << "Not a target" << endl;
		}
	}
	else if (input.toLower().subStringFind("display") != nullptr) {
		if (input.toLower().subStringFind("inventory") != nullptr) {
			Player.displayInventory();
		}
		else if (input.toLower().subStringFind("equipment") != nullptr) {
			// broken
			Player.displayEquipment();
		}
	}
	else if (input.toLower().subStringFind("equip") != nullptr)
	{
		for (int i = 0; i < Player.invetorySize(); ++i) {
			if (input.toLower().subStringFind(Player.itemName(i).toLower(), 6) != nullptr) {
				Player.equipItem(Player.itemName(i));
			}
		}
	}
	else if (input.toLower().subStringFind("use") != nullptr)
	{
		bool targeted = false;
		bool potion = false;
		for (Character* target : targetList) {
			if (input.toLower().subStringFind(target->name().toLower()) != nullptr) {
				for (int i = 0; i < Player.invetorySize(); ++i) {
					if (input.toLower().subStringFind(Player.itemName(i).toLower()) != nullptr)
					{
						Player.usePotion(*target, Player.itemName(i));
						potion = true;
						break;
					}
				}
				targeted = true;
				break;
			}
		}
		if (!targeted && !potion) {
			cout << "Not a target\n";
		}
		else if (targeted && !potion) {
			cout << "You dont have that potion\n";
		}
	}
	else if (input.toLower().subStringFind("move") != nullptr)
	{
		if (targetList.size() > 1)
		{
			cout << "The " << targetList[1]->name() << " blocks your path\n";
		}
		else {
			if (input.toLower().subStringFind("north") != nullptr) {
				Player.m_y++;
				testForEvent(targetList);
			}
			else if (input.toLower().subStringFind("east") != nullptr) {
				Player.m_x++;
				testForEvent(targetList);
			}
			else if (input.toLower().subStringFind("west") != nullptr) {
				Player.m_x--;
				testForEvent(targetList);
			}
			else if (input.toLower().subStringFind("south") != nullptr) {
				Player.m_y--;
				testForEvent(targetList);
			}
			else {
				cout << "woah there, cant go that way\n";
			}
		}
	}
	else {
		cout << "Unknown command\n";
	}
}
int main()
{
	targets targetList;
	srand(time(NULL));
	String Input;
	cout << "input name: ";
	Character player(30, Input.Returnline());
	player.addHealthPotion("Normal Potion", 3, 10);
	targetList.push_back(&player);
	playing = true;
	while (playing == true)
	{
		command(Input.Returnline(), targetList, player);
	}
	system("PAUSE");
	return 0;
}