//
// Created by msd on 6/27/18.
//

#include "../headers/ball.h"
//#include "../headers/renderer.h"
#include <thread>
#include <iostream>
#include <chrono>


//#include "../main.cpp"
//#include "../headers/renderer.h"

Ball::Ball(float x, float y, float Vx, float Vy, int value, std::string color) {
    this->x = x;
    this->y = y;
    this->Vx = Vx;
    this->Vy = Vy;
    this->Ax = -3;
    this->Ay = -3;
    this->color = color;
    this->value = value;
}


void Ball::set_x(float x) {
    this->x = x;
}

void Ball::set_y(float y) {
    this->y = y;
}

void Ball::set_Vy(float Vy) {
    this->Vy = Vy;
    if (Vy > 0)
        this->Ay = -3;
    if (Vy < 0)
        this->Ay = 3;
    if (Vy == 0)
        this->Ay = 0;
}

void Ball::set_Vx(float Vx) {
    this->Vx = Vx;
    if (Vx > 0)
        this->Ax = -3;
    if (Vx < 0)
        this->Ax = 3;
    if (Vx == 0)
        this->Ax = 0;
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

Ball *Ball::get_ball() {
    return this;
}

int Ball::get_value() {
    return this->value;
}

std::string Ball::get_color() {
    return this->color;
}


void Ball::goal() {
    this->x = -100;
    this->y = -100;
    this->Vx = 0;
    this->Vy = 0;
    this->Ax = 0;
    this->Ay = 0;
}