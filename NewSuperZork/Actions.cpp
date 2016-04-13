#include "ThisString.h"
#include "World.h"

bool World::DropPick(const char* object){

	return NULL;
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
			printf("- %s\n%s\n", rooms[i].name, rooms[i].desc);
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
