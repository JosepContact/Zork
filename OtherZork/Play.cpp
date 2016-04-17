#include <stdio.h>
#include "World.h"



enum words { ONE_WORD = 1, TWO_WORDS, THREE_WORDS, FOUR_WORDS };

bool World::Play(){
	int number_words = 1;
	uint i;
	char c = NULL;
	char action[30], *fp = action;
	bool valaction = false; // valaction will know if we should go outside the Play func and check position again.

	// GAME LOOP
	do {
		//ASK ACTION
		printf("Action: ");
		//GET ACTION
		fgets(action, 30, stdin);
		String input(fp);
		Vector<String> Support;
		Support = input.Tokenize(Support);
		// Counts how many words have been inputed to later switch(n_words):
		for (i = 0; i < strlen(action); c = action[i++]){
			if (c == ' ') number_words++;
		}

		//Get the action alone
		switch (number_words){
		case ONE_WORD:
			if (input == "quit\n"){
				return true;
			}
			else if ((input == "inventory\n") || (input == "inv\n") || (input == "i\n")){
				Inventory();
			}
			else if (input == "go\n"){ // no direction inputed case
				printf("Go where?\n");
			}
			else if (input == "look\n"){
				valaction = true; //we don't have to call the function just go out of loop and the main() will do it
			}
			// --------- Moves ----------------
			else if ((input == "north\n") || (input == "n\n")){
				valaction = updatepos(n);
			}
			else if ((input == "south\n") || (input == "s\n")){
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
			if (Support[0] == "go"){
				if ((players->currentpos == "Egyptian") && (!puzzle)){
					if (Support[1] == "north") puzzle = Puzzle();
					else if (Support[1] == "east") printf("You can't go that way.\n");
					else if (Support[1] == "west") printf("You can't go that way.\n");
					else if (Support[1] == "south") valaction = updatepos(s);
				}
				else if (Support[1] == "north") valaction = updatepos(n);
				else if (Support[1] == "south") valaction = updatepos(s);
				else if (Support[1] == "east") valaction = updatepos(e);
				else if (Support[1] == "west") valaction = updatepos(w);
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
			else if (input == "look east\n"){
				lookexit(e);
			}
			else if ((input == "open door\n") || (input == "close door\n")){ // there can be from 1 to 4 doors
				printf("What door?\n");
			}
			//-------------LOOK_ITEMS-------------
			else if ((Support[0] == "look")){
				if (!LookItem(Support[1])) printf("That item is not in your inventory, check 'inventory'.\n");
			}
			//--------------PICK_DROP_ITEMS-----------
			else if ((Support[0] == "pick")){
				PickItem(Support[1]);
			}
			else if ((Support[0] == "drop")){
				DropItem(Support[1]);
			}
			//-------------EQUIP UNEQUIP ITEMS-----------
			else if ((Support[0] == "equip")){
				EquipItem(Support[1]);
			}
			else if ((Support[0] == "unequip")){
				UnequipItem(Support[1]);
			}
			else printf("What?\n");
			break;
		case THREE_WORDS:

			// ----------OPEN/CLOSE DOORS --------------
			if ((input == "open south door\n") || (input == "open door south\n") || (input == "unlock south door\n") || (input == "unlock door south\n")){
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
		case FOUR_WORDS:
			// --------- GET THE ROD ---------------
			if (((Support[0] == "put") || (Support[0] == "place")) && ((Support[2] == "into") || (Support[2] == "inside") || (Support[2] == "on"))) {
				if (!GetRod(Support[1], Support[3])){
					printf("Are you sure you can do that?\n");
				}
			}
			else{
				printf("What...?\n");
			}
			break;
		default:
			printf("Too many words.\n");
			break;
		}
		number_words = 1;
	} while (!valaction);
	return false;
}
