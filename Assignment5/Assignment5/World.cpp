#include "World.h"
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

World::World()
{
	//makes all the elements null first
	for (int y = 0; y < GRID_HEIGHT; y++)
	{
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			grid[x][y] = NULL;
		}
	}

	srand(time(NULL));
	int i = 0;
	int x, y;
	//generates ants
	while (i < NUMBER_OF_ANTS)
	{
		x = rand() % GRID_WIDTH + 0;
		y = rand() % GRID_HEIGHT + 0;
		if (grid[x][y] == NULL)
		{
			grid[x][y] = new ant(this, GRID_WIDTH, GRID_HEIGHT);
			grid[x][y]->setPosition(x, y);
			i++;
		}
	}

	i = 0;
	//generates ant lions
	while (i < NUMBER_OF_ANT_LIONS)
	{
		x = rand() % GRID_WIDTH + 0;
		y = rand() % GRID_HEIGHT + 0;
		if (grid[x][y] == NULL)
		{
			grid[x][y] = new lion(this, GRID_WIDTH, GRID_HEIGHT);
			grid[x][y]->setPosition(x, y);
			i++;
		}
	}
}

World::~World()
{

}

Organism* World::getOrganism(int x, int y)
{
	return grid[x][y];
}

void World::setOrganism(Organism *organism, int x, int y)
{
	this->grid[x][y] = organism;
	this->grid[x][y]->setPosition(x, y);
}

void World::move()
{
	round++;
	for (int y = 0; y < GRID_HEIGHT; y++)
	{
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			if (grid[x][y] != NULL)//check has something in it
			{
				if (this->grid[x][y]->isTurn() == true)//check if it already went
				{
					int i = grid[x][y]->move();
					if (grid[x][y]->getMoved() == true)//if it did move
					{
						grid[x][y] = NULL;
					}
				}
			}
		}
	}

	for (int y = 0; y < GRID_HEIGHT; y++)
	{
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			if (grid[x][y] != NULL)
			{
				grid[x][y]->endTurn();
			}
		}
	}
}

int World::getCountOfObject(int i)
{
	int count = 0;
	for (int y = 0; y < GRID_HEIGHT; y++)
	{
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			if (grid[x][y] != NULL)
				if (grid[x][y]->getSpecies() == i)
					count++;
		}
	}
	return count;
}

int World::getRound()
{
	return round;
}

ostream& operator<<(ostream &output, World &world)
{
	for (int y = 0; y < GRID_HEIGHT; y++)
	{
		//SetConsoleTextAttribute(hConsole, y);
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			//SetConsoleTextAttribute(hConsole, y);
			if (world.grid[x][y] == NULL)
				output << " ";
			else
				output << world.grid[x][y];
		}
		output << endl;
	}
	return output;
}