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
	Vector<Item> inventory;
	Vector<Item> craftable;
	Vector<Item> equipment;

public: //play.cpp && actions.cpp
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
	void World::PickItem(const String & item);
	void World::DropItem(const String & item);
	void World::EquipItem(const String & item);
	void World::UnequipItem(const String & item);
public: //world.cpp
	bool World::room_sub_travel(const char* item_name, uint&) const;
	int World::item_sub_travel(const char * item_name , uint n_room) const;
	bool World::inventory_sub_travel(const char* item_name, uint&) const;
	int World::player_sub_travel(const char* player_pos) const;
	const Vector<Item> & World::clear_at(uint pos, Vector<Item> & items);
	bool World::equipment_sub_travel(const char* item_name, uint& int_ret) const;
};

#endif
