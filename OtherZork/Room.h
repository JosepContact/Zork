#include "Entity.h"
#include "Item.h"
#ifndef ROOM_H_
#define ROOM_H_
enum room_names { Entrance = 0, Hall, Security, Romanticism, Alley, Gargoyle, Egyptian, Store, Greek, Minotaur, Inventory = 10, Null= 11};


class Room : public Entity {
public:
	Vector<Item> Location;
	virtual ~Room(){
		delete[] Location.buffer;
	}
};

#endif
