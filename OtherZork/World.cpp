#include "World.h"

bool World::room_sub_travel(const char* item_name, uint& int_ret) const {

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < rooms[i].Location.num_elements; ++j){
			if (item_name == rooms[i].Location.buffer[j].name){
				int_ret = i;
				return true;
			}
		}
	}
	printf("ERROR AT ROOM_SUB_TRAVEL FUNC\n");
	return false;
}
int World::player_sub_travel(const char* player_pos) const {
	for (int i = 0; i < 10; i++){
		if (rooms[i].name == player_pos){
			return i;
		}
	}
	//printf("ERROR AT PLAYER_SUB_TRAVEL FUNC\n");
	assert(0);
	return 0;
}
int World::item_sub_travel(const char* item_name, uint n_room) const {

	for (int i = 0; i < rooms[n_room].Location.num_elements; i++){
		
		if (rooms[n_room].Location.buffer[i].name == item_name) {
			return i;
		}
		
	}
	assert(0);
	//printf("ERROR AT ITEM_SUB_TRAVEL FUNC\n");
	return 0;
}
bool World::inventory_sub_travel(const char* item_name, uint& int_ret) const{
	for (int i = 0; i < inventory.num_elements; ++i){
		if (inventory.buffer[i].name == item_name){
			int_ret = i;
			return true;
		}
	}
	//printf("ERROR AT INVENTORY_SUB_TRAVEL FUNC\n");
	return false;
}

bool World::equipment_sub_travel(const char* item_name, uint& int_ret) const
{
	for (int i = 0; i < equipment.num_elements; ++i){
		if (equipment.buffer[i].name == item_name){
			int_ret = i;
			return true;
		}
	}
	return false;
}

const Vector<Item> & World::clear_at(uint pos, Vector<Item> & items){
	items[pos].name = '\0';
	items[pos].desc = '\0';
	for (; (items.num_elements - pos) > 1;++pos){
		items.buffer[pos] = items.buffer[pos + 1];
	}

	items.num_elements--;
	return items;
}
