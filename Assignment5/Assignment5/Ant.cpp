#include "Ant.h"
#include "World.h"

#include <stdlib.h>
#include <time.h>

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

int ant::move()
{	
	int r = rand() % 5 + 1;
	switch (r)
	{
	case WEST:
		if (this->world->getOrganism(x - 1, y) == NULL)
		{
			this->world->setOrganism(this, x - 1, y);
			moved = true;
			return WEST;
		}
		break;
	case EAST:
		if (this->world->getOrganism(x + 1, y) == NULL && (x + 1) < width)
		{
			this->world->setOrganism(this, x + 1, y);
			moved = true;
			return EAST;
		}
		break;
	case NORTH:
		if (this->world->getOrganism(x, y - 1) == NULL)
		{
			this->world->setOrganism(this, x, y - 1);
			moved = true;
			return NORTH;
		}
		break;
	case SOUTH:
		if (this->world->getOrganism(x, y + 1) == NULL && (y + 1) < height)
		{
			this->world->setOrganism(this, x, y + 1);
			moved = true;
			return SOUTH;
		}
		break;
	default:
		break;
	}
}
