#include <stdio.h>
#include "MemLeaks.h"
#include "World.h"


int main(void){
	ReportMemoryLeaks();
	World Museum;
	bool game = false;
	Museum.CreateWorld();
	do {
		Museum.currpos();
		game = Museum.Play();
	} while (!game);
	printf("Thanks for playing!\n");
	getchar();

	return 0;

}