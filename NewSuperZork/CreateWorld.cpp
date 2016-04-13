#include "World.h"
#include "ThisString.h"

#define NROOM 10
#define NPLAY 1
#define NEXIT 9
#define NITEM 10

World::World(){
	rooms = new Room[NROOM];
	players = new Player;
	exits = new Exit[NEXIT];
	items = new Item[NITEM];
}

void World::CreateWorld(){

	//Adding name and description to the rooms
	// ------------ ROOMS ---------------
	rooms[0].name = "Entrance";
	rooms[1].name = "Hall";
	rooms[2].name = "Security";
	rooms[3].name = "Romanticism";
	rooms[4].name = "Alley";
	rooms[5].name = "Gargoyle";
	rooms[6].name = "Egyptian";
	rooms[7].name = "Store";
	rooms[8].name = "Greek";
	rooms[9].name = "Minotaur";

	rooms[0].desc = "At the west you spot several ticket windows. There are huge beautiful columns around you that have pictures of the art that can be found in the museum.\n'Looks like this is the spot!' you think.";
	rooms[1].desc = "There is a huge tomb in the center of the room next to some tall archs. Weird unexplainable pieces of art are all around.\nYou can see a staircase leading to the north.";
	rooms[2].desc = "Old tiny room with some screens and a desktop.";
	rooms[3].desc = "The paintings here are very well made but very depressing. The light is also poor bringing sad atmosphere.";
	rooms[4].desc = "It's very dark because the clouds are covering the moon. Lightinings momentarily illuminate the alley while your clothes get wet in seconds.\nYou can see some windows at the north.";
	rooms[5].desc = "The darkest creature you have ever seen stays idle while looking through the window. It should be a statue but perhaps the flickering lights from the hellish room are making it seem more than alive.";
	rooms[6].desc = "A squared sized room with four pillars and four mythological statues representing mythological gods.\n There is a mural covering each of the walls.";
	rooms[7].desc = "It's too dark to barely see anything.";
	rooms[8].desc = "The statue of Athena in the center might be four meters tall, looks like she's holding a shield with both hands. The room is very well illuminated thanks to the torches placed on the floor.\n 'Is this still part of the museum?' you think.";
	rooms[9].desc = "The infamous creature looks at you straight in the eyes. Fortunately, its limbs have been gripped with titanic chains\n";

	//The player should start in the ENTRANCE
	players->currentpos = "Entrance";
	

	// The exits are PATHS that connect two rooms
	// ------------- PATHS --------------
	// 0.Entrance - Hall
	exits[0].room1 = "Entrance";
	exits[0].room2 = "Hall";
	exits[0].name = "Arch";
	exits[0].desc = "There is a cool arch, looks like there may be a room behind it.";
	exits[0].dir1 = n;
	exits[0].dir2 = s;
	exits[0].locked = false;

	// 1.Alley - Hall
	exits[1].room1 = "Alley";
	exits[1].room2 = "Hall";
	exits[1].name = "Emergency Door";
	exits[1].desc = "There's an emergency door right there. The light says 'EXIT'.";
	exits[1].dir1 = e;
	exits[1].dir2 = w;
	exits[1].locked = false;

	// 2.Security - Hall
	exits[2].room1 = "Security";
	exits[2].room2 = "Hall";
	exits[2].name = "Wooden Door";
	exits[2].desc = "You can see a wooden door. The word 'SECURITY' has been printed on it.";
	exits[2].dir1 = w;
	exits[2].dir2 = e;
	exits[2].locked = false;


	// 3.Hall - Romanticism
	exits[3].room1 = "Hall";
	exits[3].room2 = "Romanticism";
	exits[3].name = "Staircase";
	exits[3].desc = "A beautiful white marble staircase that leads to darkness.";
	exits[3].dir1 = n;
	exits[3].dir2 = s;
	exits[3].locked = false;


	// 4.Gargoyle - Romanticism
	exits[4].room1 = "Gargoyle";
	exits[4].room2 = "Romanticism";
	exits[4].name = "Arch";
	exits[4].desc = "There is a cool arch, the lightning storm helps you to discern some creepy silhouettes. Are they moving?";
	exits[4].dir1 = e;
	exits[4].dir2 = w;
	exits[4].locked = false;

	// 5.Store - Romanticism
	exits[5].room1 = "Store";
	exits[5].room2 = "Romanticism";
	exits[5].name = "Wooden Door";
	exits[5].desc = "It's just a door.";
	exits[5].dir1 = w;
	exits[5].dir2 = e;
	exits[5].locked = true;

	// 6.Gargoyle - Egyptian
	exits[6].room1 = "Gargoyle";
	exits[6].room2 = "Egyptian";
	exits[6].name = "Arch";
	exits[6].desc = "There is a cool arch, looks like there may be a room behind it.";
	exits[6].dir1 = n;
	exits[6].dir2 = s;
	exits[6].locked = false;

	// 7.Romanticism - Greek
	exits[7].room1 = "Romanticism";
	exits[7].room2 = "Greek";
	exits[7].name = "Gates";
	exits[7].desc = "'Some big gates we have right here huh.' You think.";
	exits[7].dir1 = n;
	exits[7].dir2 = s;
	exits[7].locked = true;

	// 8.Minotaur - Greek
	exits[8].room1 = "Minotaur";
	exits[8].room2 = "Greek";
	exits[8].name = "Epic Gates";
	exits[8].desc = "Each gate has an intimidating Gorgon portrayed. These big gates are slightly opened, you can make it through.";
	exits[8].dir1 = w;
	exits[8].dir2 = e;
	exits[8].locked = false;

	// ------------- ITEMS --------------

	items[0].name = "Mirror";
	items[1].name = "Lantern";
	items[2].name = "Shiny Emerald";
	items[3].name = "Sword";
	items[4].name = "Shield";
	items[5].name = "Piece Of Rod";
	items[6].name = "Rod Of Aftermath";
	items[7].name = "Store Room Key";
	items[8].name = "Greek Room Key";
	items[9].name = "Core Of Power";


	items[0].desc = "It glows, the border is made of silver.";
	items[1].desc = "It's a regular lantern.";
	items[2].desc = "This tiny piece could cost hundreds of dollars. Looks like it can be inserted somewhere.";
	items[3].desc = "It's sharp and hard but not heavy at all.";
	items[4].desc = "It's the toughest and lightest material I have ever seen! If it truly belonged to Athena, I can see why.";
	items[5].desc = "Just a part of the Rod, I'm yet to find the main thing";
	items[6].desc = "A sinister aura can be seen, it's darker than the night. You feel the evilness inside of it.";
	items[7].desc = "Because it's a key and it says 'Store'...";
	items[8].desc = "It's big and it says 'Greek Room'. You are not ashamed of your size though, you are a man.";
	items[9].desc = "Two rings, one inside of the other are spinning very quickly, there's something inside that reminds you of a nebula.\n'So cool' You say out loud.";

	//YOU START WITH ONLY THE PIECE OF ROD SO

	//0.Mirror
	items[0].currentpos = "Alley";
	items[0].free = true;

	//1.Lantern
	items[0].currentpos = "Entrance";
	items[1].free = true;
	//2.Shiny Emerald
	items[0].currentpos = "Egyptian";
	items[2].free = false;
	//3.Sword
	items[0].currentpos = "Hall";
	items[3].free = false;
	//4.Shield
	items[0].currentpos = "Greek";
	items[4].free = false;
	//5.Piece Of Rod
	items[0].currentpos = "Inventory";
	items[5].free = true;
	//6.Rod Of Aftermath
	items[0].currentpos = "None";
	items[6].free = false;
	//7.Store Room Key
	items[0].currentpos = "Security";
	items[7].free = false;
	//8.Greek Room Key
	items[0].currentpos = "Security";
	items[7].free = true;
	//9.Core Of Unlimted Power
	items[0].currentpos = "Minotaur";
	items[7].free = false;
}

World::~World(){
	//Solves memory leaks
	delete[] exits;
	delete players;
	delete[] rooms, items;
}
