#pragma once
#ifndef pokemon_h
#define pokemon_h
#include <string>
#include <iostream>
using namespace std;

class Pokemon

{
private:

	int attackPower;

	int hp;


public:
	Pokemon();

	void setAttackPower();

	int getAttackPower();

	void setHealth();

	int getHealth();

	int showHp(int hp, int enemyattack);

};

#endif
