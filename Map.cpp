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
