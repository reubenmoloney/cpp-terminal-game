#include "Enemy.h"

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
	if(playerY < x){
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

