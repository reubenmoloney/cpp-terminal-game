#ifndef BULLET_H
#define BULLET_H

class Bullet {
private:
  int x;
  int y;
  char direction;// N , W , E, S
  int speed = 2;
  int age = 0;
public:
  Bullet(int startX, int startY, char moveDirection);
  int getX();
  int getY();
  void move();
  int getAge();
};

#endif