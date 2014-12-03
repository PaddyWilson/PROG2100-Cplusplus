#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

class weapon
{
public:
	weapon()
	{

	}

	double calcSwordDamage()
	{
		return 5+rand();
	}

	double calcFlameDamage()
	{
		return 10 + rand() % 20;
	}
};

class character
{
public:

	char charType;
	double health;
	int dex;
	int strenth;
	int armour;
	weapon weap;

	character()
	{

	}

	void calc(double damage)
	{
		health = health - damage;
	}

	double getHealth()
	{
		return health;
	}



};




int main()
{
	string 



	_getch();
	return 0;
}
