#include <stdio.h>
#include <string.h>
#include "World.h"

enum words {ONE_WORD = 1, TWO_WORDS, THREE_WORDS};

bool World::Play(){
		int n_words = 1, i;
		char c = NULL, action[100];
		bool valaction = false; // valaction will know if we should go outside the Play func and check position again.
		do {
			printf("Action: ");
			fgets(action, 20, stdin);
			// Counts how many words have been inputed to later switch(n_words):
			for (i = 0; i < strlen(action); c = action[i++]){
				if (c == ' ') n_words++;
			}
			switch (n_words){
			case ONE_WORD:
				if ((strcmp(action, "quit\n")) == 0){
					return true;
				}
				else if (strcmp(action, "go\n") == 0){ // no direction inputed case
					printf("Go where?\n");
				}
				else if (strcmp(action, "look\n") == 0){
					valaction = true; //we don't have to call the function just go out of loop and the main() will do it
				}
				// --------- Moves ----------------
				else if ((strcmp(action, "north\n") == 0) || (strcmp(action, "n\n") == 0)){
					valaction = updatepos(n);
				}
				else if ((strcmp(action, "south\n") == 0) || (strcmp(action, "s\n") == 0)){
					valaction = updatepos(s);
				}
				else if ((strcmp(action, "east\n") == 0) || (strcmp(action, "e\n") == 0)){
					valaction = updatepos(e);
				}
				else if ((strcmp(action, "west\n") == 0) || (strcmp(action, "w\n") == 0)){
					valaction = updatepos(w);
				}
				// --------------------------------
				else if (strcmp(action, "help\n") == 0){ // help command
				HelpCommand();
				}
				else printf("I don't know such action\n");
				break;
			case TWO_WORDS:
				// --------------MOVES---------------
				if ((strcmp(action, "go north\n") == 0)){
					valaction = updatepos(n);
				}
				else if ((strcmp(action, "go south\n") == 0)){
					valaction = updatepos(s);
				}
				else if ((strcmp(action, "go east\n") == 0)){
					valaction = updatepos(e);
				}
				else if ((strcmp(action, "go west\n") == 0)){
					valaction = updatepos(w);
				}
				//--------------LOOK_EXITS--------------
				else if ((strcmp(action, "look south\n") == 0)){
					lookexit(s);
				}
				else if ((strcmp(action, "look west\n") == 0)){
					lookexit(w);
				}
				else if ((strcmp(action, "look north\n") == 0)){
					lookexit(n);
				}
				else if ((strcmp(action, "look east\n") == 0)){
					lookexit(e);
				}
				else if ((strcmp(action, "open door\n") == 0) || ((strcmp(action, "close door\n") == 0))){ // there can be from 1 to 4 doors
					printf("What door?\n");
				}
				else printf("What?\n");
				break;
			case THREE_WORDS:

				// ----------OPEN/CLOSE DOORS --------------
				if ((strcmp(action, "open south door\n") == 0) || ((strcmp(action, "open door south\n") == 0)) || (strcmp(action, "unlock south door\n") == 0) || ((strcmp(action, "unlock door south\n") == 0))){
					OpenDoor(s);
				}
				else if ((strcmp(action, "open east door\n") == 0) || ((strcmp(action, "open door east\n") == 0)) || (strcmp(action, "unlock east door\n") == 0) || ((strcmp(action, "unlock door east\n") == 0))){
					OpenDoor(e);
				}
				else if ((strcmp(action, "open north door\n") == 0) || ((strcmp(action, "open door north\n") == 0)) || (strcmp(action, "unlock north door\n") == 0) || ((strcmp(action, "unlock door north\n") == 0))){
					OpenDoor(n);
				}
				else if ((strcmp(action, "open west door\n") == 0) || ((strcmp(action, "open door west\n") == 0)) || (strcmp(action, "unlock west door\n") == 0) || ((strcmp(action, "unlock door west\n") == 0))){
					OpenDoor(w);
				}
				else if ((strcmp(action, "close south door\n") == 0) || ((strcmp(action, "close door south\n") == 0)) || (strcmp(action, "lock south door\n") == 0) || ((strcmp(action, "lock door south\n") == 0))){
					CloseDoor(s);
				}
				else if ((strcmp(action, "close east door\n") == 0) || ((strcmp(action, "close door east\n") == 0)) || (strcmp(action, "lock east door\n") == 0) || ((strcmp(action, "lock door east\n") == 0))){
					CloseDoor(e);
				}
				else if ((strcmp(action, "close north door\n") == 0) || ((strcmp(action, "close door north\n") == 0)) || (strcmp(action, "lock north door\n") == 0) || ((strcmp(action, "lock door north\n") == 0))){
					CloseDoor(n);
				}
				else if ((strcmp(action, "close west door\n") == 0) || ((strcmp(action, "close door west\n") == 0)) || (strcmp(action, "lock west door\n") == 0) || ((strcmp(action, "lock door west\n") == 0))){
					CloseDoor(w);
				}
				else printf("What?\n");
				break;
			default: 
				printf("Too many words.\n");
				break;

		}
			n_words = 1;
		} while (!valaction);
		return false;
}

void World::HelpCommand() const{
	// ------- HELP COMMANDS----------
	printf("If you are in trouble you can try these commands:\ngo + (direction).\nlook or look + (direction)\nopen or unlock door + (direction)\nclose or lock door + (direction)\nquit");
	NEWLINE;
}

// -------- CLOSE AND OPEN DOORS COMMANDS ------------
void World::CloseDoor(const int &direction){
	int i = 0;
	for (i = 0; (i < 9); ++i){
		if ((strcmp(exits[i].room1, players[0].currentpos) == 0) && (exits[i].dir1 == direction) || (strcmp(exits[i].room2, players[0].currentpos) == 0) && (exits[i].dir2 == direction)){
			if (exits[i].locked == false){
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
		if ((strcmp(exits[i].room1, players[0].currentpos) == 0) && (exits[i].dir1 == direction) || (strcmp(exits[i].room2, players[0].currentpos) == 0) && (exits[i].dir2 == direction)){
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
	int i = 0;
	for (i = 0; i < 10; i++){
		if (strcmp(rooms[i].name, players[0].currentpos) == 0){
			printf("- %s\n%s\n", rooms[i].name, rooms[i].desc);
			NEWLINE;
		}
	}
}

// ----------- CHECKS THE EXITS IN BOTH WAYS --------------
bool World::updatepos(const int &direction){
	int i = 0;
	bool success = false;
	for (i = 0; (i < 9) && (!success); ++i){
		if ((strcmp(exits[i].room1, players[0].currentpos) == 0) && (exits[i].dir1 == direction)){
			if (exits[i].locked == true){ // But can we go that way?
				printf("The door is closed\n");
				return false;
			}
			else {
				strcpy_s(players[0].currentpos, exits[i].room2);
				return true;
				success = true;
			}
		}
	}
	for (i = 0; (i < 9) && (!success); ++i){
		if ((strcmp(exits[i].room2, players[0].currentpos) == 0) && (exits[i].dir2 == direction)){
			if (exits[i].locked == true){
				printf("The door is closed\n");
				return false;
		}
			else {
				strcpy_s(players[0].currentpos, exits[i].room1);
				return true;
			}
		}
	}
	printf("There is no exit that way.\n"); //If there's no exit
	return false;
}
// ----------- How does the exit look like? -----------
void World::lookexit (const int &direction) const{
	int i = 0;
	for (i = 0; (i < 9); ++i){
		if ((strcmp(exits[i].room1, players[0].currentpos) == 0) && (exits[i].dir1 == direction) || (strcmp(exits[i].room2, players[0].currentpos) == 0) && (exits[i].dir2 == direction)){
			printf("- %s\n%s\n", exits[i].name, exits[i].desc);
			NEWLINE;
			}
		}
	}