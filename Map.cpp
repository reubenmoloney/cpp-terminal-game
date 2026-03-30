#include "Map.h"
#include <iostream>

Map::Map(){
    flip();
}

void Map::flip(){
    for(int i = 0; i<height; i++){
        for(int j = 0; j<width; j++){
            map[i][j] = '.';
        }
    }
}

void Map::drawPlayer(int x, int y){
    map[y][x] = 'P';
}

void Map::drawEnemy(int x, int y){
    map[y][x] = 'E';
}

void Map::print() {
    std::string output = "\n\n\n\n\n\n";

    for(int y = 0; y<height; y++){
        for(int x = 0; x<width; x++){
            output += map[y][x];
        }
        output += "\n";
    }
    std::cout << output;
}

void Map::gameOver(){
    int w = width/2 -5;
    int h = height/2 - 1;
    map[h][w] = 'G';
    map[h][w+1] = 'A';
    map[h][w+2] = 'M';
    map[h][w+3] = 'E';
    map[h][w+4] = ' ';
    map[h][w+5] = 'O';
    map[h][w+6] = 'V';
    map[h][w+7] = 'E';
    map[h][w+8] = 'R';
}
