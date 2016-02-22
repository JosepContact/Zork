#include <stdio.h>
#include "Header.h"

void play(char *house[3][3]) {
	int gameon = 1, x = 1, y = 1;
	printf("You are in the dining room\n");
	char move = '\0';

	do {
		move = getmove();
		switch (move) {
		case 'n':
			if ((y == 0) || (house[y][x] == "bathroom")) {
				printf("There's a wall in your way\n");
				break;
			}
			else {
				y--;
				break;
			}
		case 's':
			if ((y == 2) || (house[y][x] == "pantry") || (house[y][x] == "bathroom")) {
				printf("There's a wall in your way\n");
				break;
			}
			else {
				y++;
				break;
			}
		case 'e':
			if ((x == 2) || (house[y][x] == "bedroom")) {
				printf("There's a wall in your way\n");
				break;
			}
			else{
				x++;
				break;
			}
		case 'w':
			if (x == 1) {
				printf("There's a wall in your way\n");
				break;
			}
			else {
				x--;
				break;
			}
		} // switch ends here
		NEWLINE;
		if (move != 'q')
			printf("You are in the %s\n", house[y][x]);
	} while (move != 'q'); // end of while
} // end of function

char getmove() {
	char move;
	NEWLINE;
	printf("Go where?\n");
	scanf_s(" %c", &move, 1);
	if ((move == 'n') || (move == 's') || (move == 'e') || (move == 'w') || (move == 'q')){
		return move;
	}
	else {
		NEWLINE;
		printf("Invalid direction\n");
		return NULL;
	}
}
