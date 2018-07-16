//
// Created by msd on 6/27/18.
//

#include "../headers/ball.h"
#include "../headers/renderer.h"
#include <thread>
#include <iostream>
#include <chrono>


//#include "../main.cpp"
//#include "../headers/renderer.h"

Ball::Ball(float x, float y, float Vx, float Vy, float speed,std::string color) {
    this->x = x;
    this->y = y;
    this->Vx = Vx;
    this->Vy = Vy;
    this->color=color;
    this->speed = speed;
}

void Ball::set_speed(float speed) {
    this->speed = speed;
}

void Ball::set_x(float x) {
    this->x = x;
}

void Ball::set_y(float y) {
    this->y = y;
}

void Ball::set_Vy(float Vy) {
    this->Vy = Vy;
}

void Ball::set_Vx(float Vx) {
    this->Vx = Vx;
}

void Ball::set_Ax(float Ax) {
    this->Ax = Ax;
}

void Ball::set_Ay(float Ay) {
    this->Ay = Ay;
}

float Ball::get_x() {
    return this->x;
}

float Ball::get_y() {
    return this->y;
}

float Ball::get_Ax() {
    return this->Ax;
}

float Ball::get_Ay() {
    return this->Ay;
}

float Ball::get_Vx() {
    return this->Vx;
}

float Ball::get_Vy() {
    return this->Vy;
}
Ball* Ball::get_ball() {
    return this;
}
std::string Ball::get_color() {
    return this->color;
}
void Ball::move() {
    float delta_x = pow((this->Vx), 2) / this->Ax;
    float delta_y = pow((this->Vy), 2) / this->Ay;
    while (delta_x>0 || delta_y>0){
        if (delta_x>0)
            this->x+=0.5;
        if (delta_y>0)
            this->y+=0.5;
        delta_x-=0.5;
        delta_y-=0.5;
//        renderer(window,this);
        //std::this_thread::sleep_for(std::chrono::milliseconds(10));

    }
    //if (this->x > 600 || this->x < 0)
      //  this->set_Ax(-this->get_Ax());
    //if (this->y > 400 || this->y < 0)
      //  this->set_Ay(-this->get_Ay());
    //this->x += pow((this->Vx), 2) / this->Ax;
    //this->y += pow((this->Vy), 2) / this->Ay;


}

