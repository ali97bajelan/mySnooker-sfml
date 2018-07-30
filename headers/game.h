//
// Created by msd on 6/27/18.
//

#ifndef MYSNOOKER_GAME_H
#define MYSNOOKER_GAME_H

#include "ball.h"
#include "renderer.h"
#include <iostream>

class Game {
public:
    Game(int width, int height, Rendering *render);

    void shoot(float speed, float degree, int turn);

    void move();

    void check();

    Ball **get_balls();

    bool is_moving();

    void scores(Ball ball);
    std::string result();

private:
    Ball **balls;
    bool colision[17][17];
    int width, height, score1, score2, turn;
    bool red_color1, red_color2;
    Rendering *render;
};

#endif //MYSNOOKER_GAME_H
//