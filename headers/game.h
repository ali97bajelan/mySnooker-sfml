//
// Created by msd on 6/27/18.
//

#ifndef MYSNOOKER_GAME_H
#define MYSNOOKER_GAME_H

#include "ball.h"
#include "renderer.h"

class Game {
public:
    Game(int width,int height,Rendering *render);
    void shoot(float speed,float degree,int index);
    void move(Ball *ball);
    void check();
    Ball **get_balls();
private:
    int width,height;
    Ball **balls;
    Rendering *render;
};

#endif //MYSNOOKER_GAME_H
//