#ifndef WORLD_H_
#define WORLD_H



class World {
public:
	class rooms {
	public:
		char name[20];
		char desc[500];
		
		class exits{
		public:
			int door;
		}exit[4];


	}room[10];

public:
	void World::CreateWorld();

};


bool Play();

#endif
