#include "Lion.h"
#include "World.h"

#include <stdlib.h>
//#include <time.h>

lion::lion()
{
	//OutputDebugString("Lion Ant Constructor default\n");
	visual = "X";
	this->world = new World();
}

lion::lion(World *world, int width, int height)
{
	//OutputDebugString("Lion Ant Constructor with args\n");
	visual = "X";
	this->world = world;
	this->width = width;
	this->height = height;
}

lion::~lion()
{
	//OutputDebugString("Lion Ant Deconstructor\n");
}

int lion::getSpecies()
{
	return 2;
}

int lion::move()
{
	//cout << "Lion: x=" << x << " y=" << y << endl;
	//if ((this->world->getOrganism(x - 1, y) != NULL))// && ((x - 1) >= 0))
	//	cout << "	Can Eat" << endl;
	//	if (this->world->getOrganism(x - 1, y)->getSpecies() == 1)
	//	{
	//		cout << "	Did Eat" << endl;
	//		this->world->setOrganism(this, x - 1, y);
	//		round++;
	//		moved = true;
	//		return WEST;
	//	}


	//random move
	int r = rand() % 5 + 1;
	switch (r)
	{
	case WEST:
		if (this->world->getOrganism(x - 1, y) == NULL)
		{
			this->world->setOrganism(this, x - 1, y);
			round++;
			moved = true;
			return WEST;
		}
		break;
	case EAST:
		if (this->world->getOrganism(x + 1, y) == NULL && (x + 1) < width)
		{
			this->world->setOrganism(this, x + 1, y);
			round++;
			moved = true;
			return EAST;
		}
		break;
	case NORTH:
		if (this->world->getOrganism(x, y - 1) == NULL)
		{
			this->world->setOrganism(this, x, y - 1);
			round++;
			moved = true;
			return NORTH;
		}
		break;
	case SOUTH:
		if (this->world->getOrganism(x, y + 1) == NULL && (y + 1) < height)
		{
			this->world->setOrganism(this, x, y + 1);
			round++;
			moved = true;
			return SOUTH;
		}
		break;
	default:
		break;
	}
	
	moved = false;
	return 2000;
}
