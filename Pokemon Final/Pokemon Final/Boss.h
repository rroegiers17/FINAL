#pragma once
#ifndef Boss_h
#define Boss_h
#include <string>
#include <iostream>
using namespace std;

class Boss

{
private:

	int attackPower;

	int enemyhp;



public:

	Boss();

	void setAttackPower();

	int getAttackPower();

	void setHealth();

	int getHealth();

	int showEnemyHp(int enemyhp, int attack);

};

#endif