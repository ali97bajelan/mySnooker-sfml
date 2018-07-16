//
// Created by msd on 6/27/18.
//

#ifndef MYSNOOKER_GAME_H
#define MYSNOOKER_GAME_H

#include "ball.h"
#include "renderer.h"

class Game {
public:
    Game(int width,int height);
    //void shoot(int power, float Vx, float Vy, float Ax, float Ay);
    void shoot(float speed,float degree,int index);
    Ball **get_balls();
private:
    int width,height;
    Ball **balls;
};

#endif //MYSNOOKER_GAME_H
//