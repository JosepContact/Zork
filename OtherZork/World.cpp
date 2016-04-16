#include "World.h"

int World::room_sub_travel(const char* item_name) const {
	for (int i = 0; i < 10; i++){
		if (item_name == rooms[i].Location.buffer[0].name) return i;
	}
	printf("ERROR AT ROOM_SUB_TRAVEL FUNC\n");
	return NULL;
}
int World::player_sub_travel(const char* player_pos) const {
	for (int i = 0; i < 10; i++){
		if (rooms[i].name == player_pos) return i;
	}
	printf("ERROR AT PLAYER_SUB_TRAVEL FUNC\n");
	return NULL;
}
int World::item_sub_travel(const char* item_name, uint n_room) const {

	for (int i = 0; i < rooms[n_room].Location.num_elements; i++){
		
		if (rooms[n_room].Location.buffer[i].name == item_name) return i;
	}
	printf("ERROR AT ITEM_SUB_TRAVEL FUNC\n");
	return NULL;
}
int World::inventory_sub_travel(const char* item_name) const{
	for (int i = 0; i < inventory.num_elements; ++i){
		if (inventory.buffer[i].name == item_name) return i;
	}
	//printf("ERROR AT INVENTORY_SUB_TRAVEL FUNC\n");
	return NULL;
}