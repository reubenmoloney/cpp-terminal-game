#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
private:
	int x;
	int y;
	int speed;
	int canvaWidth;
	int canvaHeight;
public:
	Enemy(int startX, int startY, int enemySpeed, int canvaW, int canvaH);
	int getX();
	int getY();
	void goTowards(int playerX, int playerY);
};

#endif
