#include "Ant.h"
#include "World.h"

#include <stdlib.h>
#include <iomanip>

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

		/*cout << left << setw(10) << "Ant" <<
			left << setw(5) << x <<
			left << setw(5) << y <<
			left << setw(5) << round <<
			left << setw(10);*/

		//picks a random location and moves to it if it's empty
		int r = rand() % 4 + 1;
		switch (r)
		{
		case WEST:
			if (this->world->getOrganism(x - 1, y) == NULL && (x - 1) >= 0)
			{
				this->world->setOrganism(this, x - 1, y);
				moved = true;
				//cout << "West";
			}
			break;
		case EAST:
			if (this->world->getOrganism(x + 1, y) == NULL && (x + 1) < width)
			{
				this->world->setOrganism(this, x + 1, y);
				moved = true;
				//cout << "East";
			}
			break;
		case NORTH:
			if (this->world->getOrganism(x, y - 1) == NULL && (y - 1) >= 0)
			{
				this->world->setOrganism(this, x, y - 1);
				moved = true;
				//cout << "North";
			}
			break;
		case SOUTH:
			if (this->world->getOrganism(x, y + 1) == NULL && (y + 1) < height)
			{
				this->world->setOrganism(this, x, y + 1);
				moved = true;
				//cout << "South";
			}
			break;
		default:
			break;
		}

		/*if (moved == false)
		{
			cout << "No Move";
		}
		cout << left << setw(10);*/

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
			if (this->world->getOrganism(x + 1, y) == NULL && (x + 1) < width)
			{
				this->world->setOrganism(new ant(world, width, height), x + 1, y);
			}
			//north
			if (this->world->getOrganism(x, y - 1) == NULL && (y - 1) >= 0)
			{
				this->world->setOrganism(new ant(world, width, height), x, y - 1);
			}
			//south
			if (this->world->getOrganism(x, y + 1) == NULL && (y + 1) < height)
			{
				this->world->setOrganism(new ant(world, width, height), x, y + 1);
			}
			round = 0;
		}

		/*if (round == 0)
		{
			cout << "Breed";
		}
		else
			cout << "No Breed";
		cout << endl;*/
	}
	/*if (isNew == false)
	{
		cout << "New Ant" << endl;
	}*/
	isNew = true;
}
