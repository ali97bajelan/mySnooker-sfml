//
// Created by msd on 6/27/18.
//

#include "../headers/game.h"
#include <algorithm>
#include <thread>
#include <iostream>


Game::Game(int width, int height) {
    this->width = width;
    this->height = height;
    //ball = new Ball(width / 20, height / 20, 1, 1, 0,Color::White);
    this->balls = new Ball*[10];
    balls[0] = new Ball(900,340,0,0,0,Color::White);
    balls[1] = new Ball(150,300,0,0,0,Color::Red);
    balls[2] = new Ball(150,325,0,0,0,Color::Red);
    balls[3] = new Ball(150,350,0,0,0,Color::Red);
    balls[4] = new Ball(150,360,0,0,0,Color::Red);
    balls[5] = new Ball(150,380,0,0,0,Color::Red);
    balls[6] = new Ball(150,400,0,0,0,Color::Red);
    balls[7] = new Ball(150,420,0,0,0,Color::Red);
    balls[8] = new Ball(150,440,0,0,0,Color::Red);
    balls[9] = new Ball(150,460,0,0,0,Color::Red);

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
Ball **Game::get_balls() {
    return this->balls;
}