#ifndef EXIT_H
#define EXIT_H


class Exit {
	bool locked;
	char name;
	char desc;
	enum direction {s,w,n,e};
	Room * source;
	Room * destin;
};

#endif

