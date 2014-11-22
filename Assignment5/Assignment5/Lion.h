#ifndef _Lion_H
#define _Lion_H

#include "Organism.h"

class lion : public Organism
{
public:
	lion();
	lion( World *world, int width, int height );
	virtual ~lion();

	int getSpecies();
	int move();
};

#endif
