#include "Player.h"
#include <string>

Player::Player(int playerX = 0, int playerY = 0, int playerSpeed = 1, int canvaW = 30, int canvaH = 40){
	x = playerX;
	y = playerY;
	canvaWidth = canvaW;
	canvaHeight = canvaH;
	speed = playerSpeed;
}

void Player::setPos(int newX, int newY){
	x = newX;
	y = newY;
}

std::string Player::getPos(){
	std::string position;
	position += std::to_string(x);
	position += ",";
	position += std::to_string(y);
	return position;
}

void Player::setX(int newX){
	x = newX;
}

void Player::setY(int newY){
	y = newY;
}

int Player::getX(){
	return x;
}

int Player::getY(){
	return y;
}

void Player::goUp(){
	y -= speed;
	if(y < 0){
		y = 0;
	}
}

void Player::goDown(){
	y += speed;
	if(y > canvaHeight){
		y = canvaHeight;
	}
}

void Player::goLeft(){
	x -= speed;
	if(x < 0){
		x = 0;
	}
}

void Player::goRight(){
	x += speed;
	if(speed > canvaWidth){
		x = canvaWidth;
	}
}





