#include "Player.h"

Player::Player(int playerX = 0, int playerY = 0, int playerSpeed = 1){
	x = playerX;
	y = playerY;
	speed = playerSpeed;
}

void Player::setPos(int newX, int newY){
	x = newX;
	y = newY;
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
	y += speed;
}

void Player::goDown(){
	y -= speed;
}

void Player::goLeft(){
	x -= speed;
}

void Player::goRight(){
	x += speed;
}





