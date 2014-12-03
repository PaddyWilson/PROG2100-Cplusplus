#ifndef _Organism_H
#define _Organism_H

#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <iomanip>

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
	int round;
	bool isDead = false;
	bool isNew = false;

	enum { WEST = 1, NORTH, EAST, SOUTH, NUM_DIRECTIONS };

public:
	Organism();
	Organism( World *world, int width, int height );
	virtual ~Organism();

	virtual void move() = 0;
	virtual int getSpecies() = 0;
	virtual void breed() = 0;
	//virtual void spawn() = 0;
	//virtual void getPosition() = 0;

	string getVisual();

	void setPosition( int x, int y );
	void endTurn();
	bool isTurn();
	
	bool getMoved();
	bool getIsDead();
	void setMoved(bool);
	void setIsNew(bool);

	friend ostream& operator<<( ostream &output, Organism *organism );
};

#endif
