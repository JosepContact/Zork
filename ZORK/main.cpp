#include <stdio.h>
#include "World.h"
int main(void){
	World Museum;
	bool game = false;
	Museum.CreateWorld();
	do {
		game = Play(Museum);
	} while (!game);
	printf("Thanks for playing!\n");
	getchar();

	return 0;

}