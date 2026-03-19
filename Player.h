#ifndef PLAYER_H
#define PLAYER_H

class Player {
private: 
	int x;
	int y;
	int speed;

public:
	Player(int playerX, int playerY, int playerSpeed);
	void setPos(int newX, int newY);
	void setX(int newX);
	void setY(int newY);
	int getX();
	int getY();
	void goUp();
	void goDown();
	void goLeft();
	void goRight();
};

#endif
