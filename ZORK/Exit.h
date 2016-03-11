#ifndef EXIT_H
#define EXIT_H

enum direction { s, w, n, e };

class Exit {
public:

	bool locked;
	int dir1, dir2;
	char name[20], desc[200], room1[20], room2[20];
	
};

#endif

