#include <stdio.h>
#include "MemLeaks.h"
#include "World.h"
<<<<<<< HEAD:NewSuperZork/Main.cpp
=======
#include "MyString.h"
>>>>>>> origin/master:ZORK/main.cpp

int main(void){
	ReportMemoryLeaks();
	World Museum;

	bool game = false;
<<<<<<< HEAD:NewSuperZork/Main.cpp

=======
	
>>>>>>> origin/master:ZORK/main.cpp
	Museum.CreateWorld();
	do {
		Museum.currpos();
		game = Museum.Play();
	} while (!game);
	printf("Thanks for playing!\n");
	getchar();

	return 0;

}
