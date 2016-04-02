#include <stdio.h>
#include "MyString.h"
#include "World.h"



enum words {ONE_WORD = 1, TWO_WORDS, THREE_WORDS};

bool World::Play(){
		int n_words = 1, i;
		char c = NULL, action[30], *fp = action;
		bool valaction = false; // valaction will know if we should go outside the Play func and check position again.
		do {
			printf("Action: ");
			fgets(action, 30, stdin);
			String input(fp);
			// Counts how many words have been inputed to later switch(n_words):
			for (i = 0; i < strlen(action); c = action[i++]){
				if (c == ' ') n_words++;
			}
			//Get the action alone
			switch (n_words){
			case ONE_WORD:
				if (input == "quit\n"){
					return true;
				}
				else if (input == "go\n"){ // no direction inputed case
					printf("Go where?\n");
				}
				else if (input == "look\n"){
					valaction = true; //we don't have to call the function just go out of loop and the main() will do it
				}
				// --------- Moves ----------------
				else if ((input ==  "north\n") || (input == "n\n")){
					valaction = updatepos(n);
				}
				else if ((input ==  "south\n") || (input == "s\n")){
					valaction = updatepos(s);
				}
				else if ((input == "east\n") || (input == "e\n")){
					valaction = updatepos(e);
				}
				else if ((input == "west\n") || (input == "w\n")){
					valaction = updatepos(w);
				}
				// --------------------------------
				else if (input == "help\n"){ // help command
					HelpCommand();
				}
				else printf("I don't know such action\n");
				break;
			case TWO_WORDS:
				// --------------MOVES---------------
				if (input ==  "go north\n"){
					valaction = updatepos(n);
				}
				else if (input == "go south\n"){
					valaction = updatepos(s);
				}
				else if (input == "go east\n"){
					valaction = updatepos(e);
				}
				else if (input == "go west\n"){
					valaction = updatepos(w);
				}
				//--------------LOOK_EXITS--------------
				else if (input == "look south\n"){
					lookexit(s);
				}
				else if (input == "look west\n"){
					lookexit(w);
				}
				else if (input == "look north\n"){
					lookexit(n);
				}
				else if (input ==  "look east\n"){
					lookexit(e);
				}
				else if ((input == "open door\n") || ( input == "close door\n")){ // there can be from 1 to 4 doors
					printf("What door?\n");
				}
				//--------------PICK_DROP_ITEMS-----------
				else if ((input == "pick") || (input == "drop")){
					printf("dafuq");
				}
				else printf("What?\n");
				break;
			case THREE_WORDS:

				// ----------OPEN/CLOSE DOORS --------------
				if ((input == "open south door\n") || (input == "open door south\n") || (input ==  "unlock south door\n") || (input == "unlock door south\n")){
					OpenDoor(s);
				}
				else if ((input == "open east door\n") || (input == "open door east\n") || (input == "unlock east door\n") || (input == "unlock door east\n")){
					OpenDoor(e);
				}
				else if ((input == "open north door\n") || (input == "open door north\n") || (input == "unlock north door\n") || (input == "unlock door north\n")){
					OpenDoor(n);
				}
				else if ((input == "open west door\n") || (input == "open door west\n") || (input == "unlock west door\n") || (input == "unlock door west\n")){
					OpenDoor(w);
				}
				else if ((input == "close south door\n") || (input == "close door south\n") || (input == "lock south door\n") || (input == "lock door south\n")){
					CloseDoor(s);
				}
				else if ((input == "close east door\n") || (input == "close door east\n") || (input == "lock east door\n") || (input == "lock door east\n")){
					CloseDoor(e);
				}
				else if ((input == "close north door\n") || (input == "close door north\n") || (input == "lock north door\n") || (input == "lock door north\n")){
					CloseDoor(n);
				}
				else if ((input == "close west door\n") || (input == "close door west\n") || (input == "lock west door\n") || (input == "lock door west\n")){
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
bool World::DropPick(const char* object){


}

void World::HelpCommand() const{
	// ------- HELP COMMANDS----------
	printf("If you are in trouble you can try these commands:\ngo + (direction).\nlook or look + (direction)\nopen or unlock door + (direction)\nclose or lock door + (direction)\nquit");
	NEWLINE;
}

// -------- CLOSE AND OPEN DOORS COMMANDS ------------
void World::CloseDoor(const int &direction){

	String CurrentPos(players[0].currentpos);

	for (int i = 0; (i < 9); ++i){
		if ((CurrentPos == exits[i].room1) && (exits[i].dir1 == direction) || (CurrentPos == exits[i].room2) && (exits[i].dir2 == direction)){
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
	String CurrentPos(players[0].currentpos);
	for (int i = 0; i < 10; i++){
		if (CurrentPos == rooms[i].name){
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
	String CurrentPos(players[0].currentpos);
	for (int i = 0; (i < 9); ++i){
		if ((CurrentPos == exits[i].room1) && (exits[i].dir1 == direction) || (CurrentPos == exits[i].room2) && (exits[i].dir2 == direction)){
			printf("- %s\n%s\n", exits[i].name, exits[i].desc);
			NEWLINE;
			}
		}
	}

