#ifndef _WORLD_H
#define _WORLD_H

#include <iostream>
#include "Organism.h"
#include "Ant.h"
#include "Lion.h"

using namespace std;

class Organism;

const int NUMBER_OF_ANTS = 100;
const int NUMBER_OF_ANT_LIONS = 5;

const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 20;

class World
{
protected:
	Organism *grid[GRID_WIDTH][GRID_HEIGHT];
	int round = 0;

public:

	World();
	virtual ~World();

	Organism *getOrganism( int x, int y );
	void setOrganism( Organism *organism, int x, int y );

	void move();
	void moveOrganisum(int x, int y);

	int getCountOfObject(int i);
	int getRound();

	friend ostream& operator<<( ostream &output, World &world );

};

#endif
