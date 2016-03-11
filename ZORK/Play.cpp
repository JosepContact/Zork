#include <stdio.h>
#include <string.h>
#include "World.h"


bool Play(World Museum){
		int direct = 4;
		char action[20];
		char direction[20];
		bool valaction = false;
		do {
		printf("Action: ");
		fgets(action, 20, stdin);
		if ((strcmp(action, "quit\n")) == 0){
			return true;
		}
		else if (strcmp(action, "go\n") == 0){
			printf("Go where?\n");
			fgets(direction, 20, stdin);
			if ((strcmp(direction, "north\n") == 0) || (strcmp(direction, "n\n") == 0)){
				direct = 2;
			}
			else if ((strcmp(direction, "south\n") == 0) || (strcmp(direction, "s\n") == 0)){
				direct = 0;
			}
			else if ((strcmp(direction, "west\n") == 0) || (strcmp(direction, "w\n") == 0)){
				direct = 1;
			}
			else if ((strcmp(direction, "east\n") == 0) || (strcmp(direction, "e\n") == 0)){
				direct = 3;
			}
			if (direct == 0) printf("I don't know that direction\n");
		}
		else printf("I don't know such action\n");
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
