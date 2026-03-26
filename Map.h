#ifndef MAP_H
#define MAP_H

class Map {
private:
    static const int height = 30;
    static const int width = 40;
    char map[height][width];

public:
    Map();
    void drawPlayer(int playerX, int playerY);
    void print();
    void flip();
};

#endif
