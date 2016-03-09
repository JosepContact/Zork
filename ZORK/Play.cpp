#include <stdio.h>
#include <string.h>
#include "World.h"


bool Play(World Museum){
	currpos(Museum);
	char action[20];
	char direction[20];
	printf("Action: ");
	fgets(action, 20, stdin);
	if ((strcmp (action,"quit\n")) == 0){
		return true;
	}
	else if (strcmp(action, "go\n") == 0){
		printf("Go where?\n");
		fgets(direction, 20, stdin);
		getchar();
	}
	return false;
}

void currpos(World Museum){
	int i = 0;
	for (i = 0; i < 10; i++){
		if (Museum.room[i].player == true){
			printf("- %s\n%s\n", Museum.room[i].name, Museum.room[i].desc);
		}
	}
	NEWLINE;
}