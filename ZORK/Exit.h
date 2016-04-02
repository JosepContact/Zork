#include "Entity.h"

#ifndef EXIT_H
#define EXIT_H

enum direction { s, w, n, e };

class Exit: public Entity {
public:
	bool locked;
	int dir1, dir2;
	char * room1, * room2;
};
#endif

