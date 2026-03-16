//to compile: cl /EHsc yourfile.cpp User32.lib
//as we need to explicitly include the windows shite for some reason

#include <iostream>
#include <windows.h>
#include "Player.h"

int up = 87;
int down = 83;
int left = 65;
int right = 68; 
int escape = 27;


int width = 100;
int height = 100;
int main() {

	Player player(50,50,1);

	//game loop
	while(true){
		///check keyoard input
		if(GetAsyncKeyState(up) & 0x8000){
			player.goUp();
		}
		if(GetAsyncKeyState(down) & 0x8000){
			player.goDown();
		}
		if(GetAsyncKeyState(left) & 0x8000){
			player.goLeft();
		}
		if(GetAsyncKeyState(right) & 0x8000){
			player.goRight();
		}
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
        	    std::cout << "SPACE\n";
        	}
		if(GetAsyncKeyState(escape) & 0x8000){
			return 0;
		}
		
		//calculate players position based on the input
		std::cout << player.getX() << ", " << player.getY() << "\n";




		Sleep(100);
	}
	return 0;
}
