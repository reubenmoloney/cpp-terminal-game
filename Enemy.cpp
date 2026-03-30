#include "Enemy.h"
#include <string>

Enemy::Enemy(int startX, int startY, int enemySpeed, int canvaW, int canvaH){
	x = startX;
	y = startY;
	speed = enemySpeed;
	canvaWidth = canvaW;
	canvaHeight = canvaH;
}

void Enemy::goTowards(int playerX, int playerY){
	if(playerX > x){
		x += speed;
	}
	if(playerX < x){
		x -= speed;
	}
	if(playerY > y){
		y += speed;
	}
	if(playerY < y){
		y -= speed;
	}
}

int Enemy::getX(){
	return x;
}

int Enemy::getY(){
	return y;
}

std::string Enemy::getPos(){
	std::string position;
	position += std::to_string(x);
	position += ",";
	position += std::to_string(y);
	return position;
}

