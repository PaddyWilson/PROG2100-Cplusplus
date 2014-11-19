#ifndef _Organism_H
#define _Organism_H

#include <iostream>

using namespace std;

class World;

class Organism
{
protected:
	int x;
	int y;
	int width;
	int height;
	bool moved;
	World *world;

	enum { WEST, NORTH, EAST, SOUTH, NUM_DIRECTIONS };

public:
	Organism();
	Organism( World *world, int width, int height );
	virtual ~Organism();

	virtual void move() = 0;
	//virtual void spawn() = 0;
	//virtual void getSpecies() = 0;
	//virtual void getPosition() = 0;

	void setPosition( int x, int y );
	void endTurn();
	bool isTurn();

	friend ostream& operator<<( ostream &output, Organism *organism );
};

#endif
