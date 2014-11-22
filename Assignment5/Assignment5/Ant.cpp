#include "Ant.h"
#include "World.h"

#include <stdlib.h>
#include <iomanip>

ant::ant()
{
	//OutputDebugString("Ant Constructor default\n");
	visual = "O";
	this->world = new World();
}

ant::ant(World *world, int width, int height)
{
	//OutputDebugString("Ant Constructor with args\n");
	visual = "O";
	this->world = world;
	this->width = width;
	this->height = height;
}

ant::~ant()
{
	//OutputDebugString("Ant Deconstructor\n");
}

int ant::getSpecies()
{
	return 1;
}

void ant::move()
{	
	round++;//add one to the round counter
	
	cout << left << setw(10) << "Ant" <<
		left << setw(5) << x <<
		left << setw(5) << y <<
		left << setw(5) << round <<
		left << setw(10);
	int r = rand() % 4 + 1;
	switch (r)
	{
	case WEST:
		if (this->world->getOrganism(x - 1, y) == NULL && (x - 1) >= 0)
		{
			this->world->setOrganism(this, x - 1, y);
			moved = true;
			cout << "West";
		}
		break;
	case EAST:
		if (this->world->getOrganism(x + 1, y) == NULL && (x + 1) < width)
		{
			this->world->setOrganism(this, x + 1, y);
			moved = true;
			cout << "East";
		}
		break;
	case NORTH:
		if (this->world->getOrganism(x, y - 1) == NULL && (y - 1) > 0)
		{
			this->world->setOrganism(this, x, y - 1);
			moved = true;
			cout << "North";
		}
		break;
	case SOUTH:
		if (this->world->getOrganism(x, y + 1) == NULL && (y + 1) < height)
		{
			this->world->setOrganism(this, x, y + 1);
			moved = true;
			cout << "South";
		}
		break;
	default:
		break;
	}
	if (moved == false)
	{
		cout << "No Move";
	}
	cout << left << setw(10);

	if (round >= 3)
	{
		if (moved == true)
		{
			switch (r)
			{
			case WEST:
				if (this->world->getOrganism(x - 1, y) == NULL)
				{
					this->world->setOrganism(new ant(world, width, height), x - 1, y);
					round = 0;
				}
				break;
			case EAST:
				if (this->world->getOrganism(x + 1, y) == NULL && (x + 1) < width)
				{
					this->world->setOrganism(new ant(world, width, height), x + 1, y);
					round = 0;
				}
				break;
			case NORTH:
				if (this->world->getOrganism(x, y - 1) == NULL)
				{
					this->world->setOrganism(new ant(world, width, height), x, y - 1);
					round = 0;
				}
				break;
			case SOUTH:
				if (this->world->getOrganism(x, y + 1) == NULL && (y + 1) < height)
				{
					this->world->setOrganism(new ant(world, width, height), x, y + 1);
					round = 0;
				}
				break;
			default:
				break;
			}
		}
	}

	if (round == 0)
	{
		cout << "Breed";
	}
	else
		cout << "No Breed";
	cout << endl;
}
