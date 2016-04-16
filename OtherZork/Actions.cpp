#include "ThisString.h"
#include "World.h"

void World::PickItem(const String & item){
	int n_room = NULL;
	bool success = false;
	if (inventory.num_elements > 3){ // Are we already carrying 4 objects?
		printf("Your inventory is full! You cannot carry more than 4 objects.\n");
	}
	else {
		for (int i = 0; (i < 9); ++i){
			if ((item == items[i].name) && (players->currentpos == rooms[room_sub_travel(items[i].name)].name) && (!success))
			{
				if (items[i].free)
				{
					success = true;
					n_room = room_sub_travel(items[i].name);
					printf("You picked %s.\n- \%s.", items[i].name, items[i].desc);
					// Place item in inventory
					inventory.push_back(items[i]);
					// change item 'free' state
					items[i].free = false;
					// change Location
					rooms[n_room].Location.clear_at(item_sub_travel(items[i].name ,n_room));
				}
			}
		}
	}
	if (!success) printf("Pick what?\n");
	NEWLINE;
}
void World::DropItem(const String & item){
	int n_room = NULL;
	bool success = false;
	if (inventory.num_elements == 0){ // It's empty
		printf("The inventory is empty.\n");
	}
	else {
		for (int i = 0; (i < 9); ++i){
			if ((item == items[i].name) && (items[i].name == inventory.buffer[inventory_sub_travel(items[i].name)].name) && (!success))
			{
					success = true;
					printf("You dropped %s.\n", items[i].name);
					// Place item in room
					n_room = player_sub_travel(players->currentpos);
					rooms[n_room].Location.push_back(items[i]);
					// change item 'free' state
					items[i].free = true;
					// change Location
					inventory.clear_at(inventory_sub_travel(items[i].name));
			}
		}
	}
	if (!success) printf("You don't have such object.\n");
	NEWLINE;
}






void World::HelpCommand() const{
	// ------- HELP COMMANDS----------
	printf("If you are in trouble you can try these commands:\ngo + (direction).\nlook or look + (direction)\nopen or unlock door + (direction)\nclose or lock door + (direction)\nquit");
	NEWLINE;
}

// -------- CLOSE AND OPEN DOORS COMMANDS ------------
void World::CloseDoor(const int &direction){

	for (int i = 0; (i < 9); ++i){
		if ((players->currentpos == exits[i].room1) && (exits[i].dir1 == direction) || (players->currentpos == exits[i].room2) && (exits[i].dir2 == direction)){
			if (!exits[i].locked){
				exits[i].locked = true;
				printf("You locked the door.\n");
			}
			else printf("Nothing to close\n");
		}
	}
	NEWLINE;
}
void World::OpenDoor(const int &direction){
	int i = 0;
	for (i = 0; (i < 9); ++i){
		if ((players->currentpos == exits[i].room1) && (exits[i].dir1 == direction) || (players->currentpos == exits[i].room2) && (exits[i].dir2 == direction)){
			if (exits[i].locked == true){
				exits[i].locked = false;
				printf("You unlocked the door.\n");
			}
			else printf("Nothing to open\n");
		}
	}
	NEWLINE;
}
void World::currpos() const{

	for (int i = 0; i < 10; i++){
		if (players->currentpos == rooms[i].name){
			printf("--> %s\n%s\n", rooms[i].name, rooms[i].desc);
			NEWLINE;
		}
	}
}

// ----------- CHECKS THE EXITS IN BOTH WAYS --------------
bool World::updatepos(const int &direction){

	int i = 0;
	for (i = 0; (i < 9); ++i){
		if ((players->currentpos == exits[i].room1) && (exits[i].dir1 == direction)){
			if (exits[i].locked == true){ // But can we go that way?
				printf("The door is closed\n");
				return false;
			}
			else {
				players->currentpos = exits[i].room2;
				return true;
			}
		}
	}
	for (i = 0; (i < 9); ++i){
		if ((players->currentpos == exits[i].room2) && (exits[i].dir2 == direction)){
			if (exits[i].locked == true){
				printf("The door is closed\n");
				return false;
			}
			else {
				players->currentpos = exits[i].room1;
				return true;
			}
		}
	}
	printf("There is no exit that way.\n"); //If there's no exit
	return false;
}
// ----------- How does the exit look like? -----------
void World::lookexit(const int &direction) const{

	for (int i = 0; (i < 9); ++i){
		if ((players->currentpos == exits[i].room1) && (exits[i].dir1 == direction) || (players->currentpos == exits[i].room2) && (exits[i].dir2 == direction)){
			printf("- %s\n%s\n", exits[i].name, exits[i].desc);
			NEWLINE;
		}
	}
}