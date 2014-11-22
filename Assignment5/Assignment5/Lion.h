#ifndef _Lion_H
#define _Lion_H

#include "Organism.h"

class lion : public Organism
{
protected:
	int lastRoundEaten;

public:
	lion();
	lion( World *world, int width, int height );
	virtual ~lion();

	int getSpecies();
	void move();
};

#endif
