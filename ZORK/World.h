#include "Player.h"
#include "Room.h"
#include "Exit.h"


#ifndef WORLD_H_
#define WORLD_H_
#define NEWLINE printf("\n");
class World {
public:
	Room * rooms;
	Exit * exits;
	Player * players;

public:
	void World::CreateWorld();
	bool World::Play();
	World::~World();
	bool World::updatepos(const int &);
	void World::lookexit(const int &) const;
	void World::OpenDoor(const int &);
	void World::CloseDoor(const int &);
	void World::currpos() const;
	void World::HelpCommand() const;
};

#endif

