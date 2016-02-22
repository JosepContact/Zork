#include <stdio.h>
#include "Header.h"

int main(void) {

	int game;
	char *house[3][3] = { { "x", "kitchen",		"pantry" },
						{ "x",	 "dining room",	"bathroom" },
						{ "x",	 "bedroom",		"x" } };
	play(house);
	printf("\n\tGoodbye!\n\n");


	system("pause");
	return 0;

}