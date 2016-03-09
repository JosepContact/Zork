#include <stdio.h>
#include "World.h"
int main(void){
	
	
	bool game = false;

	do {
		game = Play();


	} while (!game);
	printf("Thanks for playing\n");
	getchar();
	return 0;

}