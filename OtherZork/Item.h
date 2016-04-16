#include "Entity.h"

#ifndef ITEM_H_
#define ITEM_H_
enum item_names { mirror = 0, lantern, shiny_emerald, sword, shield, piece_of_rod, rod_of_aftermath, store_room_key, greek_room_key, core_of_power };
class Item : public Entity{
public:
	bool free;

};


#endif
