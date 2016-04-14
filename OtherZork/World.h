#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"

#ifndef WORLD_H_
#define WORLD_H_
#define NEWLINE printf("\n");
class World {
public:
	Room * rooms;
	Exit * exits;
	Player * players;
	Item * items;

public:
	World::World();
	void World::CreateWorld();
	bool World::Play();
	virtual World::~World();
	bool World::updatepos(const int &);
	void World::lookexit(const int &) const;
	void World::OpenDoor(const int &);
	void World::CloseDoor(const int &);
	void World::currpos() const;
	void World::HelpCommand() const;
	bool World::DropPick(const char* object);
};

#endif
