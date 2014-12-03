#include "Organism.h"
#include <string>

Organism::Organism() :visual(" "), moved(false), round(0)
{
	
}

Organism::Organism(World *world, int width, int height) : visual(" "), world(world), width(width), height(height), moved(false), round(0)
{
	
}

Organism::~Organism()
{
	
}

//move get/set
bool Organism::getMoved()
{
	return moved;
}
void Organism::setMoved(bool a)
{
	this->moved = a;
}

//is new item set
void Organism::setIsNew(bool a)
{
	this->isNew = a;
}

//visual get
string Organism::getVisual()
{
	return this->visual;
}

//sets the x y of the organism
void Organism::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

//end turn method
void Organism::endTurn()
{
	moved = false;
}

//is it it's turn
bool Organism::isTurn()
{
	if (moved == false)
	{
		return true;
	}
	return false;
}

bool Organism::getIsDead()
{
	return isDead;
}

ostream& operator<<(ostream &output, Organism *organism)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (organism->getSpecies() == 1)//prints Ants as yellow O's
	{
		SetConsoleTextAttribute(hConsole, 14);//sets color
	}
	else if (organism->getSpecies() == 2)//prints Ant Lions as cyan X's
	{
		SetConsoleTextAttribute(hConsole, 11);//sets color
	}
	else
	{
		output << " ";
		return output;
	}
	output << organism->getVisual();
	return output;
}