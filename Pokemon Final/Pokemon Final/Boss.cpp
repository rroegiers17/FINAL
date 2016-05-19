#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include "Boss.h"

Boss::Boss() // constructor
{
	srand(time(NULL));
}

void Boss::setAttackPower() // setting attack power
{
	//number from 10-20
	attackPower = rand() % 20 + 8;
}

int Boss::getAttackPower() // getting the attack power from number generator
{
	attackPower = rand() % 20 + 8;
	return attackPower;
}

void Boss::setHealth() // set boss health to 400
{
	//set health
	enemyhp = 400;
}

int Boss::getHealth() //get boss health
{
	enemyhp = 400;
	return enemyhp;
}

int Boss::showEnemyHp(int enemyhp, int attack) // display the boss health for the user
{
	return enemyhp - attack;
}
