#include "World.h"
#include "string.h"

void World::CreateWorld(){
	rooms = new Room[10];
	players = new Player[1];
	exits = new Exit[9];
	
	//Adding name and description to the rooms
	// ------------ ROOMS ---------------
	strcpy_s(rooms[0].name, "Entrance");
	strcpy_s(rooms[1].name, "Hall");
	strcpy_s(rooms[2].name, "Security");
	strcpy_s(rooms[3].name, "Romanticism");
	strcpy_s(rooms[4].name, "Alley");
	strcpy_s(rooms[5].name, "Gargoyle");
	strcpy_s(rooms[6].name, "Egyptian");
	strcpy_s(rooms[7].name, "Store");
	strcpy_s(rooms[8].name, "Greek");
	strcpy_s(rooms[9].name, "Minotaur");

	strcpy_s(rooms[0].desc, "At the west you spot several ticket windows. There are huge beautiful columns around you that have pictures of the art that can be found in the museum.\n'Looks like this is the spot!' you think.");
	strcpy_s(rooms[1].desc, "There is a huge tomb in the center of the room next to some tall archs. Weird unexplainable pieces of art are all around.\nYou can see a staircase leading to the north.");
	strcpy_s(rooms[2].desc, "Old tiny room with some screens and a desktop.");
	strcpy_s(rooms[3].desc, "The paintings here are very well made but very depressing. The light is also poor bringing sad atmosphere.");
	strcpy_s(rooms[4].desc, "It's very dark because the clouds are covering the moon. Lightinings momentarily illuminate the alley while your clothes get wet in seconds.\nYou can see some windows at the north.");
	strcpy_s(rooms[5].desc, "The darkest creature you have ever seen stays idle while looking through the window. It should be a statue but perhaps the flickering lights from the hellish room are making it seem more than alive.");
	strcpy_s(rooms[6].desc, "A squared sized room with four pillars and four mythological statues representing mythological gods.\n There is a mural covering each of the walls.");
	strcpy_s(rooms[7].desc, "It's too dark to barely see anything.");
	strcpy_s(rooms[8].desc, "The statue of Athena in the center might be four meters tall, looks like she's holding a shield with both hands. The room is very well illuminated thanks to the torches placed on the floor.\n 'Is this still part of the museum?' you think.");
	strcpy_s(rooms[9].desc, "The infamous creature looks at you straight in the eyes. Fortunately, its limbs have been gripped with titanic chains\n");

	//The player should start in the ENTRANCE

	strcpy_s(players[0].currentpos, "Entrance");

	// The exits are PATHS that connect two rooms
	// ------------- PATHS --------------
	// 0.Entrance - Hall
	strcpy_s(exits[0].room1, "Entrance");
	strcpy_s(exits[0].room2, "Hall");
	strcpy_s(exits[0].name, "Arch");
	strcpy_s(exits[0].desc, "There is a cool arch, looks like there may be a room behind it.");
	exits[0].dir1 = n;
	exits[0].dir2 = s;
	exits[0].locked = false;

	// 1.Alley - Hall
	strcpy_s(exits[1].room1, "Alley");
	strcpy_s(exits[1].room2, "Hall");
	strcpy_s(exits[1].name, "Emergency Door");
	strcpy_s(exits[1].desc, "There's an emergency door right there. The light says 'EXIT'.");
	exits[1].dir1 = e;
	exits[1].dir2 = w;
	exits[1].locked = false;

	// 2.Security - Hall
	strcpy_s(exits[2].room1, "Security");
	strcpy_s(exits[2].room2, "Hall");
	strcpy_s(exits[2].name, "Wooden Door");
	strcpy_s(exits[2].desc, "You can see a wooden door. The word 'SECURITY' has been printed on it.");
	exits[2].dir1 = w;
	exits[2].dir2 = e;
	exits[2].locked = false;


	// 3.Hall - Romanticism
	strcpy_s(exits[3].room1, "Hall");
	strcpy_s(exits[3].room2, "Romanticism");
	strcpy_s(exits[3].name, "Staircase");
	strcpy_s(exits[3].desc, "A beautiful white marble staircase that leads to darkness.");
	exits[3].dir1 = n;
	exits[3].dir2 = s;
	exits[3].locked = false;
	

	// 4.Gargoyle - Romanticism
	strcpy_s(exits[4].room1, "Gargoyle");
	strcpy_s(exits[4].room2, "Romanticism");
	strcpy_s(exits[4].name, "Arch");
	strcpy_s(exits[4].desc, "There is a cool arch, the lightning storm helps you to discern some creepy silhouettes. Are they moving?");
	exits[4].dir1 = e;
	exits[4].dir2 = w;
	exits[4].locked = false;

	// 5.Store - Romanticism
	strcpy_s(exits[5].room1, "Store");
	strcpy_s(exits[5].room2, "Romanticism");
	strcpy_s(exits[5].name, "Wooden Door");
	strcpy_s(exits[5].desc, "It's just a door.");
	exits[5].dir1 = w;
	exits[5].dir2 = e;
	exits[5].locked = true;

	// 6.Gargoyle - Egyptian
	strcpy_s(exits[6].room1, "Gargoyle");
	strcpy_s(exits[6].room2, "Egyptian");
	strcpy_s(exits[6].name, "Arch");
	strcpy_s(exits[6].desc, "There is a cool arch, looks like there may be a room behind it.");
	exits[6].dir1 = n;
	exits[6].dir2 = s;
	exits[6].locked = false;

	// 7.Romanticism - Greek
	strcpy_s(exits[7].room1, "Romanticism");
	strcpy_s(exits[7].room2, "Greek");
	strcpy_s(exits[7].name, "Gates");
	strcpy_s(exits[7].desc, "'Some big gates we have right here huh.' You think.");
	exits[7].dir1 = n;
	exits[7].dir2 = s;
	exits[7].locked = true;

	// 8.Minotaur - Greek
	strcpy_s(exits[8].room1, "Minotaur");
	strcpy_s(exits[8].room2, "Greek");
	strcpy_s(exits[8].name, "Epic Gates");
	strcpy_s(exits[8].desc, "Each gate has an intimidating Gorgon portrayed. These big gates are slightly opened, you can make it through.");
	exits[8].dir1 = w;
	exits[8].dir2 = e;
	exits[8].locked = false;
}

World::~World(){
	//Solves memory leaks
	delete exits;
	delete players;
	delete rooms;
}