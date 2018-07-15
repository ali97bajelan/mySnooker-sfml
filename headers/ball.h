//
// Created by msd on 6/27/18.
//

#ifndef MYSNOOKER_BALL_H
#define MYSNOOKER_BALL_H

#include <math.h>
#include <SFML/Graphics.hpp>
//#include "game.h"

using namespace sf;
class Ball {
public:
    Ball(float x, float y, float Vx, float Vy, float speed,std::string color);
    float get_x();
    float get_y();
    float get_Ax();
    float get_Ay();
    float get_Vx();
    float get_Vy();
    std::string get_color();
    void set_x(float x);
    void set_y(float y);
    void set_Vx(float Vx);
    void set_Vy(float Vy);
    void set_Ax(float Ax);
    void set_Ay(float Ay);
    void move(RenderWindow*);
    void set_speed(float speed);
    Ball * get_ball();
private:
    float x,y,Vx,Vy,Ax,Ay,speed;
    std::string color;
};

#endif //MYSNOOKER_BALL_H
