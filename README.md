# Terminal based C++ game
IDK I needed to do something and this let me start using separate files, objects, and some other bits and bobs I hadn't touched in cpp before.
It only works on windows for now - didn't have my linux machine on me when I started it so will probably add support as soon as I clone it onto it.

# How to compile
one of the following:
- `cl /EHsc main.cpp Player.cpp Map.cpp User32.lib`
- `g++ main.cpp Player.cpp Map.cpp` lol gcc compiler mogs

# Current

So far there is a matrix in which the P can be moved around using wasd

# TODO 
- enemey that moves around
- player health 
- collisions with player and enemy
- add a way to destroy enemies? projectile maybe?
- possibly add some sort of collisions with a wall - probably not though
