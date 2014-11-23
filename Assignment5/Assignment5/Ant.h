#ifndef _Ant_H
#define _Ant_H

#include "Organism.h"

class ant : public Organism
{
public:
	ant(); 
	ant( World *world, int width, int height );
	virtual ~ant();

	int getSpecies();
	void move();
	void breed();
};

#endif
