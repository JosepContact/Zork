#include "Entity.h"

#ifndef ITEM_H_
#define ITEM_H_
enum item_names { mirror = 0, lantern, emerald, sword, shield, piece, rod, key, core };
class Item : public Entity{
public:
	bool free;

};


#endif
