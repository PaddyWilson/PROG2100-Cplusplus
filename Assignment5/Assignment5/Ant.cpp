#include "Ant.h"
#include "World.h"

//default constuctor
ant::ant()
{
	visual = "O";
	this->world = new World();
}

//constuctor take in the world along with its width and height
ant::ant(World *world, int width, int height)
{
	visual = "O";
	this->world = world;
	this->width = width;
	this->height = height;
}

//deconstuctor
ant::~ant()
{
	
}

//gets the species for ants which is one
int ant::getSpecies()
{
	return 1;
}

// moves the ants
void ant::move()
{	
	if (isNew == true)//if its not a new ant it moves
	{
		round++;//add one to the round counter
		
		//picks a random location and moves to it if it's empty
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
		default:
			break;
		}//end switch
	}//end if (isNew == true)
	isNew = true;
}

//makes a new ant if this ant has survived 3 rounds
void ant::breed()
{
	//checks if it can breed
	//places a new ant in the postion the intial lion was
	if (round >= 3)
	{
		//west
		if (this->world->getOrganism(x - 1, y) == NULL && (x - 1) >= 0)
		{
			this->world->setOrganism(new ant(world, width, height), x - 1, y);
		}
		//east
		else if (this->world->getOrganism(x + 1, y) == NULL && (x + 1) < width)
		{
			this->world->setOrganism(new ant(world, width, height), x + 1, y);
		}
		//north
		else if (this->world->getOrganism(x, y - 1) == NULL && (y - 1) >= 0)
		{
			this->world->setOrganism(new ant(world, width, height), x, y - 1);
		}
		//south
		else if (this->world->getOrganism(x, y + 1) == NULL && (y + 1) < height)
		{
			this->world->setOrganism(new ant(world, width, height), x, y + 1);
		}
		round = 0;
	}
}
