#include <stdio.h>
#include <string.h>
#include "World.h"

enum words {ONE_WORD = 1, TWO_WORDS};

bool Play(World Museum){
		int n_words = 1, i = 0, direction;
		char c = NULL;
		char action[100];
		bool valaction = false;
		do {
			printf("Action: ");
			fgets(action, 20, stdin);
			for (i = 0; i < strlen(action); c = action[i++]){
				if (c == ' ') n_words++;
			}
			switch (n_words){
			case ONE_WORD:
				if ((strcmp(action, "quit\n")) == 0){
					return true;
				}
				else if (strcmp(action, "go\n") == 0){
					printf("Go where?\n");
				}
				break;
			case TWO_WORDS:
				if ((strcmp(action, "go north\n") == 0)){
					valaction = updatepos(Museum, n);
					//if (valaction == false) printf("There is no exit that way.\n");
				}
				else if ((strcmp(action, "go south\n") == 0)){
					valaction = updatepos(Museum, s);
					//if (valaction == false) printf("There is no exit that way.\n");
				}
				else if ((strcmp(action, "go east\n") == 0)){
					valaction = updatepos(Museum, e);
					//if (valaction == false) printf("There is no exit that way.\n");
				}
				else if ((strcmp(action, "go west\n") == 0)){
					valaction = updatepos(Museum, w);
					//if (valaction == false) printf("There is no exit that way.\n");
				}
				else printf("I don't know such action\n");
				break;
		}
			n_words = 1;
		} while (!valaction);
		return false;
}

void currpos(World Museum){
	int i = 0;
	for (i = 0; i < 10; i++){
		if (strcmp(Museum.rooms[i].name, Museum.players[0].currentpos) == 0){
			printf("- %s\n%s\n", Museum.rooms[i].name, Museum.rooms[i].desc);
		}
	}
	NEWLINE;
}

bool updatepos(World Museum, const int direction){
	int i = 0;
	bool success = false;
	for (i = 0; (i < 9) && (!success); ++i){
		if ((strcmp(Museum.exits[i].room1, Museum.players[0].currentpos) == 0) && (Museum.exits[i].dir1 == direction)){
			if (Museum.exits[i].locked == true){
				printf("The door is closed\n");
				return true;;
			}
			else {
				strcpy_s(Museum.players[0].currentpos, Museum.exits[i].room2);
				return true;
				success = true;
			}
		}
	}
	for (i = 0; (i < 9) && (!success); ++i){
		if ((strcmp(Museum.exits[i].room2, Museum.players[0].currentpos) == 0) && (Museum.exits[i].dir2 == direction)){
			if (Museum.exits[i].locked == true){
				printf("The door is closed\n");
				return true;
		}
			else {
				strcpy_s(Museum.players[0].currentpos, Museum.exits[i].room1);
				return true;
			}
		}
	}
	return false;
}
