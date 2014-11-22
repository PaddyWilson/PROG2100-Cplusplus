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
	cout << "this: " << this->world << " " << world << endl;
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
	//srand(time(NULL)*time(0)/2);
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
		if (this->world->getOrganism(x + 1, y) == NULL)
		{
			this->world->setOrganism(this, x + 1, y);
			moved = true;
			return EAST;
		}
		break;
	case NORTH:
		if (this->world->getOrganism(x, y-1) == NULL)
		{
			this->world->setOrganism(this, x, y-1);
			moved = true;
			return NORTH;
		}
		break;
	case SOUTH:
		if (this->world->getOrganism(x, y + 1) == NULL)
		{
			this->world->setOrganism(this, x, y + 1);
			moved = true;
			return SOUTH;
		}
		break;
	default:
		break;
	}
	
	

	//bool n = false, s = false, e = false, w = false;
	//int many = 0;

	////north
	//if ((y - 1) >= 0 && (y + 1) < height && (x + 1) < width && (x - 1) >= 0)
	//{
	//if (world->getOrganism(x, y - 1) != NULL && world->getOrganism(x, y - 1)->getSpecies() == 1)
	//{
	//	n = true;
	//	many++;
	//}

	////south
	//if (world->getOrganism(x, y + 1) != NULL &&world->getOrganism(x, y + 1)->getSpecies() == 1)
	//{
	//	s = true;
	//	many++;
	//}

	////east
	//if (world->getOrganism(x + 1, y) != NULL && world->getOrganism(x + 1, y)->getSpecies() == 1)
	//{
	//	e = true;
	//	many++;
	//}

	////west
	//	if (world->getOrganism(x - 1, y) != NULL && world->getOrganism(x - 1, y)->getSpecies() == 1)
	//	{
	//		w = true;
	//		many++;
	//	}
	//}

	//if (e == true)
	//{
	//	world->setOrganism(new lion(world, width, height), x + 1, y);
	//	return EAST;
	//}
	//else if (w == true)
	//{
	//	world->setOrganism(new lion(world, width, height), x - 1, y);
	//	return WEST;
	//}
	//else if (n == true)
	//{
	//	world->setOrganism(new lion(world, width, height), x, y - 1);
	//	return NORTH;
	//}
	//else if (s == true)
	//{
	//	world->setOrganism(new lion(world, width, height), x, y + 1);
	//	return SOUTH;
	//}

	//srand(time(NULL));
	//int r = rand() % 4 + 1;
	//switch (r)
	//{
	//case NORTH:
	//	if (world->getOrganism(x, y-1) == NULL)
	//	{
	//		world->setOrganism(this, x, y - 1);
	//	}
	//	break;
	//case SOUTH:
	//	if (world->getOrganism(x, y +1) == NULL)
	//	{
	//		world->setOrganism(this, x, y + 1);
	//	}
	//	break;
	//case EAST:
	//	if (world->getOrganism(x + 1, y) == NULL)
	//	{
	//		world->setOrganism(this, x + 1, y);
	//	}
	//	break;
	//case WEST:
	//	if (world->getOrganism(x - 1, y) == NULL)
	//	{
	//		world->setOrganism(this, x - 1, y);
	//	}
	//	break;
	//default:
	//	break;
	//}
	//moved = true;
	return 2000;
}
