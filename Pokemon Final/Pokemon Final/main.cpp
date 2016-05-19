//
//  Katie Ochoa and Rachel Roegiers
//  Final Project
//  CS 172-1
//

/*
Players:
punch-kick-special power

Giovanni players:
-Persian
-Tauros


CHANGES: two bosses and all have the same moves: punch, kick, and a special power
*/


#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "Pokemon.h"
#include "Boss.h"
using namespace std;


// moved this info to header anc cpp files
/*void Pokemon::setAttackPower()
{
	//number from 15-20
	attackPower = rand() % 20 + 15;
}

void Pokemon::setHealth()
{
	//set health
	hp = 100;
}

int Pokemon::getHealth()
{
	return hp;
}

void Boss::setAttackPower()
{
	//number from 10-20
	attackPower = rand() % 20 + 10;
}

void Boss::setHealth()
{
	//set health
	enemyhp = 400;
}

int Boss::getHealth()
{
	return enemyhp;
}*/

/*int Boss::showEnemyHp(int enemyhp, int attack)
{
	return enemyhp - attack;
}

int Pokemon::showHp(int hp, int enemyattack)
{
	return hp - enemyattack;
}
*/

int main()
{
	// options of pokemon to choose from
	string Mewtow;
	string Gastly;
	string Rhyhorn;
	string Pikachu;
	string Venomoth;

	string player1; // the pokemon the user chose


	cout << "Hello, are you ready to battle?" << endl;
	cout << "If so, please select a Pokemon you wish to take into battle." << endl;
	cout << endl;
	cout << "Mewtow" << endl;
	cout << "Gastly" << endl;
	cout << "Rhyhorn" << endl;
	cout << "Pikachu" << endl;
	cout << "Venomoth" << endl;
	cout << endl;
	cin >> player1;

	cout << "You selected " << player1 << endl;

	Pokemon p; // declares a pokemon object
	Boss b; // declare boss object
	srand(time(NULL));
	int a = rand() % 1;
	if ((a = 0)) // picks which boss pokemon will be battling
		cout << "and you will be battling Persian!" << endl;
	else
		cout << "and you will be battling Tauros!" << endl;

	cout << endl;

	cout << player1 << " is starting with a health of 300, " <<
		"while the enemy has 400." << endl;
	
	int hp = p.getHealth(), enemyhp = b.getHealth(), attack = p.getAttackPower(), enemyattack = b.getAttackPower();

	int x;

	do
	{
		// ask user if they would like to attack ant then show the impact the attack had on the boss
		cout << "Attack? 1-Yes or 2-No" << endl;
		cin >> x;
		if (x == 1)
		{
			int y;
			cout << "Do you want to: 1-Kick, 2-Punch, 3-Special Power" << endl;
			cin >> y;
			if (y == 1)
			{
				cout << "You kicked the Boss and now he has " << b.showEnemyHp(enemyhp, attack) << "HP left." << endl;
				enemyhp = b.showEnemyHp(enemyhp, attack);
				if (enemyhp == 0) // cout bosses hp and say player wins if it equals 0 or below
				{
					cout << "Congratulations! You beat the Boss!" << endl;
				}
			}
			else if (y == 2)
			{
				cout << "You Punched the Boss and now he has " << b.showEnemyHp(enemyhp, attack) << "HP left." << endl;
				enemyhp = b.showEnemyHp(enemyhp, attack);
				if (enemyhp == 0) // cout bosses hp and say player wins if it equals 0 or below
				{
					cout << "Congratulations! You beat the Boss!" << endl;
				}
			}
			else if (y == 3)
			{
				cout << "You used your Special Power on the Boss and now he has " << b.showEnemyHp(enemyhp, attack) << "HP left." << endl;

				enemyhp = b.showEnemyHp(enemyhp, attack);
				if (enemyhp == 0) // cout bosses hp and say player wins if it equals 0 or below
				{
					cout << "Congratulations! You beat the Boss!" << endl;
				}
			}
			else
			{
				cout << "That is not a valid choice." << endl;
			}
			cout << endl;

			cout << "The Boss hit you back.\n";
			cout << "You now have " << p.showHp(hp, enemyattack) << "HP left.\n\n";
			hp = p.showHp(hp, enemyattack); // declaring hp as the showing of the players health
			if (hp == 0) // determines if player has died or not
			{
				cout << "Oh no you died! Bummer." << endl;
			}
		}
		else if (x == 2)
		{
			cout << "You chose not to hit and was attacked.";
			cout << "You now have " << hp << "HP left.\n\n";
			if (hp == 0) // determines if player has died or not
			{
				cout << "Oh no you died! Bummer." << endl;
			}
		}
		else
		{
			cout << "That is not a valid choice.\n\n";

		}



	} while (hp > 0 && enemyhp > 0); // continue looping until one of the players have died

	

	fstream save;
	int wins;
	save.open("saveData.txt", ios::in); // the file was not saving originally so we had to open and close then open and close to make it work correctly
	save >> wins;
	save.close();

	if (hp <= 0)
	{
		
		cout << "Oh no you died! Bummer. " << endl;

	}
	else if (enemyhp <= 0)
	{
		
		cout << "You killed the boss! woot woot! " << endl;
		wins++;  // if you won, the wins will be added to the saveDate text file to keep track of wins

	}
	save.open("saveData.txt", ios::out);
	save << wins;
	// save << "You have " << wins << " win(s)!";
	save.close();



	return 0;
}