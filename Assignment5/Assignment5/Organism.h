#ifndef _Organism_H
#define _Organism_H

#include <iostream>
#include <Windows.h>

using namespace std;

class World;

class Organism
{
protected:
	string visual;
	int x;
	int y;
	int width;
	int height;
	bool moved;
	World *world;

	enum { WEST = 1, NORTH, EAST, SOUTH, NUM_DIRECTIONS };

public:
	Organism();
	Organism( World *world, int width, int height );
	virtual ~Organism();

	virtual int move() = 0;
	//virtual void spawn() = 0;
	virtual int getSpecies() = 0;
	//virtual void getPosition() = 0;

	string getVisual();

	void setPosition( int x, int y );
	void endTurn();
	bool isTurn();

	bool getMoved();
	void setMoved(bool);

	friend ostream& operator<<( ostream &output, Organism *organism );
};

#endif
