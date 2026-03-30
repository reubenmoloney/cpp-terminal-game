//to compile: cl /EHsc main.cpp Player.cpp Enemy.cpp Map.cpp User32.lib
//as we need to explicitly include the windows shite for some reason

#include <iostream>
#include <windows.h>
#include "Player.h"
#include "Map.h"
#include "Enemy.h"

int up = 87;
int down = 83;
int left = 65;
int right = 68; 
int escape = 27;


int width = 40;
int height = 30;
int main() {

	Player player(0,0,1, width, height);
	Enemy enemy(width,height,1,width,height);
	Map map;
	//game loop
	while(true){
		///check keyoard input
		if(GetAsyncKeyState(up) & 0x8000){
			player.goUp();
		}
		if(GetAsyncKeyState(down) & 0x8000){
			player.goDown();
		}
		if(GetAsyncKeyState(left) & 0x8000){
			player.goLeft();
		}
		if(GetAsyncKeyState(right) & 0x8000){
			player.goRight();
		}
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
        	    std::cout << "SPACE\n";
        	}
		if(GetAsyncKeyState(escape) & 0x8000){
			return 0;
		}
		enemy.goTowards(player.getX(), player.getY());
		
		//calculate players position based on the input
		//std::cout << player.getX() << ", " << player.getY() << "\n";
		map.flip();
		map.drawPlayer(player.getX(), player.getY());
		map.drawEnemy(enemy.getX(), enemy.getY());
		map.print();
		std::cout << player.getPos();



		Sleep(16);
	}
	return 0;
}
