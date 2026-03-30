#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
private: 
	int x;
	int y;
	int speed;
	int canvaWidth;
	int canvaHeight;
	int health = 100;

public:
	Player(int playerX, int playerY, int playerSpeed, int canvaWidth, int canvaHeight);
	void setPos(int newX, int newY);
	void setX(int newX);
	void setY(int newY);
	int getX();
	int getY();
	void goUp();
	void goDown();
	void goLeft();
	void goRight();
	std::string getPos();
	int getHealth();
	void lowerHealth(int ammount);
};

#endif
