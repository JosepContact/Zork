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
	bool World::updatepos(int);
	void World::lookexit(int);
	void World::currpos();
	bool World::Play();
	void World::OpenDoor(const int);
	void World::CloseDoor(const int);
	void World::HelpCommand() const;
};

#endif

