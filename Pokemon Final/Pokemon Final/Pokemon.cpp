#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include "Pokemon.h"

Pokemon::Pokemon()
{
	srand(time(NULL));
}
void Pokemon::setAttackPower() //set how much the attack
{
	//number from 20-40
	attackPower = rand() % 20 + 20;
}

int Pokemon::getAttackPower() // get the attack power from number generator
{
	attackPower = rand() % 20 + 20;
	return attackPower;
}

void Pokemon::setHealth() // set the health of pokemon
{
	//set health
	hp = 300;
}

int Pokemon::getHealth() // getting the health of pokemon
{
	hp = 300;
	return hp;
}

int Pokemon::showHp(int hp, int enemyattack) // displays the s
{
	return hp - enemyattack;
}