//to compile: cl /EHsc main.cpp Player.cpp Enemy.cpp Map.cpp User32.lib
//as we need to explicitly include the windows shite for some reason

#include <iostream>
#include <windows.h>//this is for keyboard input
#include "Player.h"
#include "Map.h"
#include "Enemy.h"
#include "Bullet.h"
#include <vector>
#include <random>


int width = 90;
int height = 30;

//FROM HERE
std::random_device rd;
std::mt19937 rng(rd());  // Mersenne Twister engine

std::uniform_int_distribution<int> xDist(0, width - 1);
std::uniform_int_distribution<int> yDist(0, height - 1);
//TO HERE - IS NOT MY CODE
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

//create bullet array and shoot function (it will add bullets to the array)
std::vector<Bullet> bullets;
int bulletInt = 0;//for iterating
int enemyInt = 0;//for iterating
int bulletLifespan = 15;
void shoot(int sourceX, int sourceY){
  bullets.push_back(Bullet(sourceX, sourceY, 'N'));
  bullets.push_back(Bullet(sourceX, sourceY, 'S'));
  bullets.push_back(Bullet(sourceX, sourceY, 'W'));
  bullets.push_back(Bullet(sourceX, sourceY, 'E'));
}


int main() {
	int score = 0;

	int roundDuration = 100;
	int round = 1;
	int roundTimer = 0;

	Player player(0,0,2, width, height);

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
            shoot(player.getX(), player.getY());
        }
		if(GetAsyncKeyState(escape) & 0x8000){
			break;
		}

		//hadle bullet logic
		for(int i = 0; i < bullets.size(); i++){
			bullets[i].move();
		}
		//destroy aged out bullets
		bulletInt = 0;
		while(bulletInt < bullets.size()){
			if(bullets[bulletInt].getAge() > bulletLifespan){
				//destroy the bullet - easier than I thought
				bullets.erase(bullets.begin() + bulletInt);
			}else{
				bulletInt++;
			}

		}

		//handle enemies logic
		for(int i = 0; i < enemies.size(); i++){
			//move towards the player
			enemies[i].goTowards(player.getX(), player.getY());
			//check if were colliding with the player
			if(checkCollision(player.getX(), player.getY(), enemies[i].getX(), enemies[i].getY())){
				player.lowerHealth(5);
			}
			
		}
		//TODO: now check for bullet collisions
		bulletInt = 0;
		while(bulletInt < bullets.size()){
			enemyInt = 0;		
			while(enemyInt < enemies.size()){
				if(bullets[bulletInt].getX() == enemies[enemyInt].getX() && bullets[bulletInt].getY() == enemies[enemyInt].getY()){
					bullets.erase(bullets.begin() + bulletInt);
					enemies.erase(enemies.begin() + enemyInt);
					bulletInt--;
					enemyInt--;
					score += 25;
					continue;
				}
				enemyInt++;
			}
			bulletInt++;
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
		for(int i = 0; i < bullets.size(); i++){
			map.drawBullet(bullets[i].getX(), bullets[i].getY());
		}
    
		map.print();
		std::cout << "Health" << getHealthBar(player.getHealth()) << " | " << player.getPos() << " | " << bullets.size();

		//ROUND LOGIC:
		roundTimer--;
		if(roundTimer < 0){
			round++;
			for(int i = 0; i < round; i++){
				enemies.push_back(Enemy(xDist(rng), yDist(rng), 1, width, height));//this line is not my code
			}
			roundTimer = roundDuration;
		}
		Sleep(50);
	}

	map.flip();
	map.gameOver();
	map.print();
	std::cout << "Score: " << score;
	return 0;
}
