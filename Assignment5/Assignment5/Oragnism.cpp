#include "Organism.h"
#include <string>

Organism::Organism() :visual(" "), moved(false)
{
	//OutputDebugString("Organism Constructor default\n");
}

Organism::Organism(World *world, int width, int height) : visual(" "), world(world), width(width), height(height), moved(false)
{
	//OutputDebugString("Organism Constructor with args\n");
}

Organism::~Organism()
{
	/*if (this->world != NULL)
	{
		delete this->world;
	}*/
}

bool Organism::getMoved()
{
	return moved;
}

void Organism::setMoved(bool a)
{
	this->moved = a;
}

//virtual void spawn() = 0;
//virtual void getSpecies() = 0;
//virtual void getPosition() = 0;

string Organism::getVisual()
{
	return this->visual;
}


void Organism::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Organism::endTurn()
{
	moved = false;
}

bool Organism::isTurn()
{
	if (moved == false)
	{
		return true;
	}
	return false;
}

ostream& operator<<(ostream &output, Organism *organism)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (organism->getVisual() == "O")
	{
		SetConsoleTextAttribute(hConsole, 14);
	}
	else if (organism->getVisual() == "X")
	{
		SetConsoleTextAttribute(hConsole, 11);
	}
	else
	{
		//SetConsoleTextAttribute(hConsole, 15);
		output << " ";
		return output;
	}
	output << organism->getVisual();
	return output;
}