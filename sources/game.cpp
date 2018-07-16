//
// Created by msd on 6/27/18.
//

#include "../headers/game.h"
#include <algorithm>
#include <thread>
#include <iostream>
#define pi 3.14159265

Game::Game(int width, int height) {
    this->width = width;
    this->height = height;
    //ball = new Ball(width / 20, height / 20, 1, 1, 0,Color::White);
    this->balls = new Ball *[17];
    balls[0] = new Ball(1100, 335, 0, 0, 0, "white");

    balls[1] = new Ball(150, 290, 0, 0, 0, "red");
    balls[2] = new Ball(150, 315, 0, 0, 0, "red");
    balls[3] = new Ball(150, 340, 0, 0, 0, "red");
    balls[4] = new Ball(150, 365, 0, 0, 0, "red");
    balls[5] = new Ball(170, 305, 0, 0, 0, "red");
    balls[6] = new Ball(170, 330, 0, 0, 0, "red");
    balls[7] = new Ball(170, 355, 0, 0, 0, "red");
    balls[8] = new Ball(190, 320, 0, 0, 0, "red");
    balls[9] = new Ball(190, 345, 0, 0, 0, "red");
    balls[10] = new Ball(210, 335, 0, 0, 0, "red");

    balls[11] = new Ball(630, 335, 0, 0, 0, "blue");
    balls[12] = new Ball(100, 335, 0, 0, 0, "black");
    balls[13] = new Ball(990, 220, 0, 0, 0, "yellow");
    balls[14] = new Ball(990, 420, 0, 0, 0, "green");
    balls[15] = new Ball(230, 335, 0, 0, 0, "purple");
    balls[16] = new Ball(990, 335, 0, 0, 0, "orange");

}

Ball **Game::get_balls() {
    return this->balls;
}

void Game::shoot(float speed, float degree, int index) {
    float Vx = speed * cos(degree);
    float Vy = speed * sin(degree);
    std::cout<<Vx<<" "<<Vy<<std::endl;

    Ball *top =get_balls()[index];
    top->set_Ax(3);
    top->set_Ay(3);
    top->set_Vx(Vx);
    top->set_Vy(Vy);
    std::cout<<top->get_x()<<" "<<top->get_y()<<std::endl;
    top->move();
    std::cout<<top->get_x()<<" "<<top->get_y()<<std::endl;

}
/*
void Game::shoot(int power, float Vx, float Vy, float Ax, float Ay) {
    ball->set_speed(power);
    ball->set_Vx(Vx);
    ball->set_Vy(Vy);
    ball->set_Ax(Ax);
    ball->set_Ay(Ay);
    //ball->move();
    //std::this_thread::sleep_for(std::chrono::milliseconds(500));


}
*/
