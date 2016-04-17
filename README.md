Zork v0.2

 (1st Delivery)
The player starts at the entrance. You can move using commands such us: go north, north, n, go south, south, s, etc.

The player can also 'look' to get their current room description again or 'look north' among other directions to get information about the exits around.

There are a total of ten rooms, by now they all have a significative name like "Minoutaur" or "Romaticism".

All the exits can be closed and two of them are already so the player will have to input 'open door (+ direction)" to keep going.
Input "quit" to leave.

Zork v0.5 (2nd Delivery)
Everything inplemented in the first delivery still works. The player can now pick and drop some items (some of them can be equipped and unequipped).
There's one item that can be crafted. The player can also check what's in the inventory (unfortunately I couldn't show if it was equipped or not), and can look the items that are inside it.

Objects:	Location:		Can be equipped:

Lantern 	Entrance		No
Sword		Hall			Yes
Mirror		Alley			No
Shield		Greek			Yes
Core		Minotaur		No
Piece		Inventory		No
Rod		MUST BE CRAFTED		Yes

Actions:	To pick an object -> pick 'object'
		To drop an object -> drop 'object'
		To equip an item  -> equip 'item'
		To uenequip an item  -> unequip 'item'
		To check inventory -> inventory (or) inv (or) i
		To look item-> look 'item' (NOTE IT MUST BE IN THE INVENTORY)
		To craft rod-> place piece inside core (or) put piece on core (NOTE YOU MUST HAVE BOTH ITEMS IN THE INVENTORY, THIS CANNOT BE UNDONE)
Special feature:

As it was talked an exits puzzle has been implemented.

How it works: In the Egyptian room the (!!!) msg will alert about the puzzle. To start, the player should go inside the portal.
When the player goes inside, all the exits become portals and if the player makes the right decisions should be able to solve it. If not, the player goes back to the regular room.

To solve the puzzle:
(inside Egyptian)-> go north
(the puzzle starts)-> go north
		-> go west
		-> go north

Once the puzzle is solved the Greek room is available. NOTE THAT THE PLAYER CAN TYPE "OPEN DOOR NORTH" TO OPEN THE DOOR INSTEAD OF SOLVING THE PUZZLE.





Github repository: 
https://github.com/JosepUPC/Zork


Made by Josep Huguet Girón

