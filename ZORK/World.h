#include "Player.h"
#include "Room.h"
#include "Exit.h"


#ifndef WORLD_H_
#define WORLD_H____
#define NEWLINE printf("\n");
class World {
public:
	Room * rooms;
	Exit * exits;
	Player * players;

public:
	void World::CreateWorld();

};
void currpos(World Museum);
bool Play(World Museum);

#endif

