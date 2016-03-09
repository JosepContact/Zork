#ifndef WORLD_H_
#define WORLD_H____
#define NEWLINE printf("\n");
class World {
public:
	class rooms {
	public:
		char name[20];
		char desc[500];
		bool player;

		class exits{
		public:
			int door=0;
		}exit[4];


	}room[10];

public:
	void World::CreateWorld();

};
void currpos(World Museum);
bool Play(World Museum);

#endif

