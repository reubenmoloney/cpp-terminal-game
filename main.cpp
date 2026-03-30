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

bool checkCollision(int x1, int y1, int x2, int y2){
	if(x1 == x2 && y1 == y2){
		return true;
	}
	return false;
}

std::string getHealthBar(int health){
	if(health < 0){
		health = 0;
	}
	std::string tempBar = "[";
	for(int i = 0; i < health; i++){
		tempBar += "|";
	}
	for(int i = 0; i < 100-health; i++){
		tempBar += ".";
	}
	tempBar += "]";
	return tempBar;
}

int width = 90;
int height = 30;
int main() {

	Player player(0,0,2, width, height);
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
		if(checkCollision(player.getX(), player.getY(), enemy.getX(), enemy.getY())){
			player.lowerHealth(5);
		}
		if(player.getHealth() < 0){
			break;
		}
		//calculate players position based on the input
		//std::cout << player.getX() << ", " << player.getY() << "\n";
		map.flip();
		map.drawPlayer(player.getX(), player.getY());
		map.drawEnemy(enemy.getX(), enemy.getY());
		map.print();
		std::cout << "Health" << getHealthBar(player.getHealth()) << " | " << player.getPos() << " | " << enemy.getPos();

		Sleep(50);
	}

	map.flip();
	map.gameOver();
	map.print();
	return 0;
}
