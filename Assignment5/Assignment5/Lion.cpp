#include "Lion.h"
#include "World.h"
#include <math.h>
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

//moves the ant lion
void lion::move()
{
	if (isNew == true)
	{
		bool ate = false;
		round++;
		
		vector<int> possibleX;
		vector<int> possibleY;
		int i = 0;
		//eats
		//searchs for possible locations
		for (int xPos = x - 1; xPos < x + 2; xPos++)
		{
			for (int yPos = y - 1; yPos < y + 2; yPos++)
			{
				//Check if we look at "our" own cell, and skip it if we do
				if (x == xPos && y == yPos || this->world->getOrganism(xPos, yPos) == NULL || xPos < 0 || yPos < 0 || xPos >= width || yPos >= height)
					continue;

				//Now do what ever checks you need to do on cell[x, y] here.
				else if (this->world->getOrganism(xPos, yPos)->getSpecies() == 1)
				{
					possibleX.push_back(xPos);
					possibleY.push_back(yPos);
					i++;
				}
			}
		}
		//if any ants where found around it
		//pick one at random to eat
		if (i != 0)
		{
			int random = rand() % i + 1;
			this->world->setOrganism(this, possibleX.at(i - 1), possibleY.at(i - 1));
			lastRoundEaten = world->getRound();
			moved = true;
			ate = true;
		}
		//end eating

		//if the ant lion has not eatin
		//move to random spot
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
				}
				break;
			case EAST:
				if (this->world->getOrganism(x + 1, y) == NULL && (x + 1) < width)//checks if cell is empty and inside the bounds of the array
				{
					this->world->setOrganism(this, x + 1, y);
					moved = true;
				}
				break;
			case NORTH:
				if (this->world->getOrganism(x, y - 1) == NULL && (y - 1) >= 0)//checks if cell is empty and inside the bounds of the array
				{
					this->world->setOrganism(this, x, y - 1);
					moved = true;
				}
				break;
			case SOUTH:
				if (this->world->getOrganism(x, y + 1) == NULL && (y + 1) < height)//checks if cell is empty and inside the bounds of the array
				{
					this->world->setOrganism(this, x, y + 1);
					moved = true;
				}
				break;
			}//end switch
		}//end if (ate == false)
	}//end if (isNew == true)

	//if the ant lion has not eatin for 3 round it dies
	if (lastRoundEaten <= (world->getRound() - 3) && isNew == true)
		this->world->setOrganism(NULL, x, y);

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

