#ifndef MAP_H
#define MAP_H
#include <string>

class Map {
private:
    static const int height = 30;
    static const int width = 90;
    char map[height][width];
    std::string topBar;

public:
    Map();
    void drawPlayer(int playerX, int playerY);
    void print();
    void flip();
    void drawEnemy(int x, int y);
    void drawBullet(int x, int y);
    void gameOver();
};

#endif
