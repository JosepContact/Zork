#include "World.h"
#include "string.h"

void World::CreateWorld(){
	rooms = new Room[10];
	players = new Player[1];

	//Adding name and description to the rooms
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
	strcpy_s(rooms[5].desc, "The darkest creature you have ever seen stays idle while looking through the window. It shoult be a statue but perhaps the flickering lights from the hellish room are making it seem more than alive.");
	strcpy_s(rooms[6].desc, "A quared sized room with four pillars and four mythological statues representing mythological gods.\n There is a mural covering each of the four walls.");
	strcpy_s(rooms[7].desc, "It's too dark to barely see anything.");
	strcpy_s(rooms[8].desc, "The statue of Athena in the center might be four meters tall, looks like she's holding a shield with both hands. The room is very well illuminated thanks to the torches placed on the floor.\n 'Is this part from the museum?' you think.");
	strcpy_s(rooms[9].desc, "The infamous creature looks at you stright in the eyes. Fortunately, its limbs have been gripped with titanic chains\n");
	
	//The player should start in the ENTRANCE

	strcpy_s(players[0].currentpos, "Entrance");
}
