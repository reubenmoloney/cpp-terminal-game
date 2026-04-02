#include "Bullet.h"

Bullet::Bullet(int startX, int startY, char moveDirection){
  x = startX;
  y = startY;
  direction = moveDirection;
}

int Bullet::getX(){
  return x;
}

int Bullet::getY(){
  return y;
}

int Bullet::move(){
  if(direction == 'n' || direction == 'N'){
    y -= speed;
  }else{
    if(direction == 's' || direction == 'S'){
      y += speed;
    }else{
      if(direction == 'w' || direction == 'W'){
        x -= speed;
      }else{
        x += speed;
      }
    }
  }

  age++;  
}

int Bullet::getAge(){
  return age;
}
