#include "World.h"
#include <stdlib.h>//for rand()
#include <time.h>//for time()

World::World()
{
	//makes all the elements null first
	for (int y = 0; y < GRID_HEIGHT; y++)
		for (int x = 0; x < GRID_WIDTH; x++)
			grid[x][y] = NULL;

	srand(time(NULL));//uses the time for a seed for random
	int i = 0;
	int x, y;
	//generates ants at random spots until they all have been generated
	while (i < NUMBER_OF_ANTS)
	{
		x = rand() % GRID_WIDTH + 0;
		y = rand() % GRID_HEIGHT + 0;
		if (grid[x][y] == NULL)
		{
			grid[x][y] = new ant(this, GRID_WIDTH, GRID_HEIGHT);
			grid[x][y]->setPosition(x, y);
			grid[x][y]->setIsNew(true);
			i++;
		}
	}

	i = 0;
	//generates ant lions at random spots until they all have been generated
	while (i < NUMBER_OF_ANT_LIONS)
	{
		x = rand() % GRID_WIDTH + 0;
		y = rand() % GRID_HEIGHT + 0;
		if (grid[x][y] == NULL)
		{
			grid[x][y] = new lion(this, GRID_WIDTH, GRID_HEIGHT);
			grid[x][y]->setPosition(x, y);
			grid[x][y]->setIsNew(true);
			i++;
		}
	}
}

//deconstructor
World::~World()
{

}

//gets the organism at x, y
Organism* World::getOrganism(int x, int y)
{
	return grid[x][y];
}

//sets a organism at x, y
//also sets that organisms x, y coord for them
void World::setOrganism(Organism *organism, int x, int y)
{
	this->grid[x][y] = organism;
	if (this->grid[x][y] != NULL)
	{
		this->grid[x][y]->setPosition(x, y);
	}
	
}

//moves the organisms on the map
void World::move()
{
	round++;//add one to the round counter

	//loops through the grid and moves the ant lions
	for (int y = 0; y < GRID_HEIGHT; y++)
		for (int x = 0; x < GRID_WIDTH; x++)
			if (grid[x][y] != NULL && grid[x][y]->getSpecies() == 2)//check has something in it and is a ant lion
				if (this->grid[x][y]->isTurn() == true)//check if it already went
				{
					grid[x][y]->move();
					if (grid[x][y] != NULL && grid[x][y]->getMoved() == true)//if it did move
					{
						grid[x][y] = NULL;
					}
				}

	//breed ant lions
	for (int y = 0; y < GRID_HEIGHT; y++)
		for (int x = 0; x < GRID_WIDTH; x++)
			if (grid[x][y] != NULL && grid[x][y]->getSpecies() == 2)//check has something in it and is a ant lion
				grid[x][y]->breed();

	//loops through the grid and moves the ant
	for (int y = 0; y < GRID_HEIGHT; y++)
		for (int x = 0; x < GRID_WIDTH; x++)
			if (grid[x][y] != NULL && grid[x][y]->getSpecies() == 1)//check has something in it and is a ant
				if (this->grid[x][y]->isTurn() == true)//check if it already went
				{
					grid[x][y]->move();//calls the organisms move function
					if (grid[x][y]->getMoved() == true)//if it did move
					{
						grid[x][y] = NULL;//sets the pointer it was previously at to null so there is mot two of them
					}
				}

	//breed ants
	for (int y = 0; y < GRID_HEIGHT; y++)
		for (int x = 0; x < GRID_WIDTH; x++)
			if (grid[x][y] != NULL && grid[x][y]->getSpecies() == 1)//check has something in it and is a ant
				grid[x][y]->breed();

	//ends the turns for the organisms
	for (int y = 0; y < GRID_HEIGHT; y++)
		for (int x = 0; x < GRID_WIDTH; x++)
			if (grid[x][y] != NULL)
				grid[x][y]->endTurn();
		
}

//returns the amout of organism specifyed
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

//returns the number os rounds that have passed
int World::getRound()
{
	return round;
}

//draw the board on a cout call
ostream& operator<<(ostream &output, World &world)
{
	for (int y = 0; y < GRID_HEIGHT; y++)
	{
		for (int x = 0; x < GRID_WIDTH; x++)
		{
			if (world.grid[x][y] == NULL)//if that cell is null it prints whitespace
				output << " ";
			else//else prints the organisms visual
				output << world.grid[x][y];
		}
		output << endl;
	}
	return output;
}