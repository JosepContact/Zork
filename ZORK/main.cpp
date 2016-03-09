#include <stdio.h>
#include "World.h"
int main(void){
	World Museum;
	bool game = false;
	Museum.CreateWorld();
	do {
		game = Play();
	} while (!game);
	printf("Thanks for playing\n");
	getchar();
	getchar();
	return 0;

}