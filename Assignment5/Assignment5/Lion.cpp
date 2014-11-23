#include "Lion.h"
#include "World.h"
#include <vector>

lion::lion()
{
	visual = "X";
	this->world = new World();
}

lion::lion(World *world, int width, int height)
{
	visual = "X";
	this->world = world;
	this->width = width;
	this->height = height;
}

lion::~lion()
{
	
}

int lion::getSpecies()
{
	return 2;
}

void lion::move()
{
	if (isNew == true)
	{
		bool ate = false;
		round++;
		cout << left << setw(10) << "Ant Lion" <<
			left << setw(4) << x <<
			left << setw(4) << y <<
			left << setw(4) << round <<
			left << setw(4) << lastRoundEaten <<
			left << setw(10);

		//eat ants in distance if it can
		//west
		if ((this->world->getOrganism(x - 1, y) != NULL && (x - 1) >= 0) && this->world->getOrganism(x - 1, y)->getSpecies() == 1)
		{
			this->world->setOrganism(this, x - 1, y);
			lastRoundEaten = world->getRound();
			moved = true;
			ate = true;
		}
		//east
		else if ((this->world->getOrganism(x + 1, y) != NULL && (x + 1) < width) && this->world->getOrganism(x + 1, y)->getSpecies() == 1)
		{
			this->world->setOrganism(this, x + 1, y);
			lastRoundEaten = world->getRound();
			moved = true;
			ate = true;
		}
		//north
		else if ((this->world->getOrganism(x, y - 1) != NULL && (y - 1) >= 0) && this->world->getOrganism(x, y - 1)->getSpecies() == 1)
		{
			this->world->setOrganism(this, x, y - 1);
			lastRoundEaten = world->getRound();
			moved = true;
			ate = true;
		}
		//south
		else if ((this->world->getOrganism(x, y + 1) != NULL && (y + 1) < height) && this->world->getOrganism(x, y + 1)->getSpecies() == 1)
		{
			this->world->setOrganism(this, x, y + 1);
			lastRoundEaten = world->getRound();
			moved = true;
			ate = true;
		}
		

		if (ate)
		{
			cout << "Ate";
		}

		//if the ant lion has not eatin
		if (ate == false)
		{
			//random move
			int r = rand() % 4 + 1;
			switch (r)
			{
			case WEST:
				if (this->world->getOrganism(x - 1, y) == NULL && (x - 1) >= 0)//checks if cell is empty and inside the bounds of the array
				{
					this->world->setOrganism(this, x - 1, y);
					moved = true;
					cout << "West";
				}
				break;
			case EAST:
				if (this->world->getOrganism(x + 1, y) == NULL && (x + 1) < width)//checks if cell is empty and inside the bounds of the array
				{
					this->world->setOrganism(this, x + 1, y);
					moved = true;
					cout << "East";
				}
				break;
			case NORTH:
				if (this->world->getOrganism(x, y - 1) == NULL && (y - 1) >= 0)//checks if cell is empty and inside the bounds of the array
				{
					this->world->setOrganism(this, x, y - 1);
					moved = true;
					cout << "North";
				}
				break;
			case SOUTH:
				if (this->world->getOrganism(x, y + 1) == NULL && (y + 1) < height)//checks if cell is empty and inside the bounds of the array
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
			
		}
	}

	//if thhe ant lion has not eatin for 3 round it dies
	/*if (lastRoundEaten <= (world->getRound() - 3))
	{
		this->world->setOrganism(NULL, NULL, NULL);
	}*/

	cout << endl;
	if (isNew == false)
	{
		cout << "New Lion" << endl;
	}
	isNew = true;
}

//makes a new ant if this ant has survived 3 rounds
void lion::breed()
{
	//checks if it can breed
	//places a new lion in the postion the intial lion was
	if (round >= 8)
	{
		//west
		if (this->world->getOrganism(x - 1, y) == NULL && (x - 1) >= 0)
		{
			this->world->setOrganism(new lion(world, width, height), x - 1, y);
			round = 0;
		}
		//east
		else if (this->world->getOrganism(x + 1, y) == NULL && (x + 1) < width)
		{
			this->world->setOrganism(new lion(world, width, height), x + 1, y);
			round = 0;
		}
		//north
		else if (this->world->getOrganism(x, y - 1) == NULL && (y - 1) >= 0)
		{
			this->world->setOrganism(new lion(world, width, height), x, y - 1);
			round = 0;
		}
		//south
		else if (this->world->getOrganism(x, y + 1) == NULL && (y + 1) < height)
		{
			this->world->setOrganism(new lion(world, width, height), x, y + 1);
			round = 0;
		}
	}
}

