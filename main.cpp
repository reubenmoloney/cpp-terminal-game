//to compile: cl /EHsc main.cpp Player.cpp Enemy.cpp Map.cpp User32.lib
//as we need to explicitly include the windows shite for some reason

#include <iostream>
#include <windows.h>
#include "Player.h"
#include "Map.h"
#include "Enemy.h"
#include "Bullet.h"
#include <vector>

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
	
  //first bullet test
  Bullet bullet(10,10,'s');

	//create enemies array/vector
	std::vector<Enemy> enemies;
	enemies.push_back(Enemy(width,height,1,width,height));
	enemies.push_back(Enemy(width,0,1,width,height));
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

    //hadle bullet logic
    bullet.move();

		//handle enemies logic
		for(int i = 0; i < enemies.size(); i++){
			//move towards the player
      enemies[i].goTowards(player.getX(), player.getY());
			//check if were colliding with the player
      if(checkCollision(player.getX(), player.getY(), enemies[i].getX(), enemies[i].getY())){
				player.lowerHealth(5);
			}
      //now check for bullet collisions
		}
	
		if(player.getHealth() < 0){
			break;
		}
		//calculate players position based on the input
		//std::cout << player.getX() << ", " << player.getY() << "\n";
    
    //time to draw!
		map.flip();
		map.drawPlayer(player.getX(), player.getY());
		for(int i = 0; i < enemies.size(); i++){
			map.drawEnemy(enemies[i].getX(), enemies[i].getY());
		}
    map.drawBullet(bullet.getX(), bullet.getY());
		map.print();
		std::cout << "Health" << getHealthBar(player.getHealth()) << " | " << player.getPos();

		Sleep(50);
	}

	map.flip();
	map.gameOver();
	map.print();
	return 0;
}
