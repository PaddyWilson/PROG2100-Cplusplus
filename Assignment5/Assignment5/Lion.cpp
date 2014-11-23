#include "Lion.h"
#include "World.h"

#include <stdlib.h>
#include <iomanip>

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

void lion::move()
{
	if (isNew == true)
	{
		round++;
		cout << left << setw(10) << "Ant Lion" <<
			left << setw(5) << x <<
			left << setw(5) << y <<
			left << setw(5) << round <<
			left << setw(10);
		/*if ((this->world->getOrganism(x - 1, y) != NULL) && ((x - 1) >= 0))
		{
		cout << "	Can Eat" << endl;
		if (this->world->getOrganism(x - 1, y)->getSpecies() == 1)
		{
		cout << "	Did Eat" << endl;
		this->world->setOrganism(this, x - 1, y);
		round++;
		moved = true;
		}
		}*/


		//random move
		int r = rand() % 4 + 1;
		switch (r)
		{
		case WEST:
			if (this->world->getOrganism(x - 1, y) == NULL && (x - 1) > 0)
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

		//checks if it can breed
		//places a new lion in the postion the intial lion was
		if (round >= 8)
		{
			if (moved == true)
			{
				switch (r)
				{
				case WEST:
					if (this->world->getOrganism(x - 1, y) == NULL)
					{
						this->world->setOrganism(new lion(world, width, height), x - 1, y);
						round = 0;
					}
					break;
				case EAST:
					if (this->world->getOrganism(x + 1, y) == NULL && (x + 1) < width)
					{
						this->world->setOrganism(new lion(world, width, height), x + 1, y);
						round = 0;
					}
					break;
				case NORTH:
					if (this->world->getOrganism(x, y - 1) == NULL)
					{
						this->world->setOrganism(new lion(world, width, height), x, y - 1);
						round = 0;
					}
					break;
				case SOUTH:
					if (this->world->getOrganism(x, y + 1) == NULL && (y + 1) < height)
					{
						this->world->setOrganism(new lion(world, width, height), x, y + 1);
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

	if (isNew == false)
	{
		cout << "New Lion" << endl;
	}
	isNew = true;
}

