# Terminal based C++ game
IDK I needed to do something and this let me start using separate files, objects, and some other bits and bobs I hadn't touched in cpp before.
It only works on windows for now - didn't have my linux machine on me when I started it so will probably add support as soon as I clone it onto it.

## How to compile
one of the following:
- `cl /EHsc main.cpp Player.cpp Map.cpp Enemy.cpp User32.lib` for visual studio compiler
- `g++ main.cpp Player.cpp Map.cpp Enemy.cpp` for gcc (lol gcc compiler mogs)

## Files
### main.cpp
This file contains the game loop, and call the function of all the other objects (so far)

### Map.cpp
This file contains all the logic for the map, it has public function for clearing, printing, and drawing things on the map.

### Player.cpp
This file contains all the internal logic for the player - it holds the position, health, and speed of the player. It has public functions for movement, get/setting its position, and get/setting its health.

### Enemy.cpp
This file contains all the internal logic for the enemy - it holds the position and speed. It has public functions for getting its position, and telling it to go towards a point.

## Current
So far there is a matrix in which the P can be moved around using wasd, an enemy follows the player, when they collide the players health goes down. Health reaches 0 -> game over

## TODO 
- add a way to destroy enemies? projectile maybe?
- add in enemies spawning over time?
- new types of enemies? bigger and slower maybe
- possibly add some sort of collisions with a wall - probably not though

## Notes
- header files are weird
- instead of my O(n^2) collision detection, im thinking a system where we have a map with entity-coord could be better. If any of the coords in the map match then there is a collision, and we can use the coord as a key to get the entities that are colliding from the map. Just a thought.
