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
	round++;//add one to the round counter
	//cout << "Lion: x=" << x << " y=" << y;
	int r = rand() % 5 + 1;
	switch (r)
	{
	case WEST:
		if (this->world->getOrganism(x - 1, y) == NULL)
		{
			this->world->setOrganism(this, x - 1, y);
			moved = true;
		}
		break;
	case EAST:
		if (this->world->getOrganism(x + 1, y) == NULL && (x + 1) < width)
		{
			this->world->setOrganism(this, x + 1, y);
			moved = true;
		}
		break;
	case NORTH:
		if (this->world->getOrganism(x, y - 1) == NULL)
		{
			this->world->setOrganism(this, x, y - 1);
			moved = true;
		}
		break;
	case SOUTH:
		if (this->world->getOrganism(x, y + 1) == NULL && (y + 1) < height)
		{
			this->world->setOrganism(this, x, y + 1);
			moved = true;
		}
		break;
	default:
		break;
	}

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
				}
				break;
			case EAST:
				if (this->world->getOrganism(x + 1, y) == NULL && (x + 1) < width)
				{
					this->world->setOrganism(new ant(world, width, height), x + 1, y);
				}
				break;
			case NORTH:
				if (this->world->getOrganism(x, y - 1) == NULL)
				{
					this->world->setOrganism(new ant(world, width, height), x, y - 1);
				}
				break;
			case SOUTH:
				if (this->world->getOrganism(x, y + 1) == NULL && (y + 1) < height)
				{
					this->world->setOrganism(new ant(world, width, height), x, y + 1);
				}
				break;
			default:
				break;
			}
		}
		round = 0;
	}
	return 1;
}
