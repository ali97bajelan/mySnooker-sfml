//
// Created by msd on 6/27/18.
//

#include "../headers/game.h"
#include <algorithm>
#include <thread>
#include <iostream>
#include <chrono>

#define pi 3.14159265

Game::Game(int width, int height, Rendering *render) {
    this->width = width;
    this->height = height;
    this->render = render;
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
    std::cout << Vx << " " << Vy << std::endl;

    Ball *top = get_balls()[index];
    //top->set_Ax(3);
    //top->set_Ay(3);
    top->set_Vx(Vx);
    top->set_Vy(Vy);
    if (Vx > 0)
        top->set_Ax(-3);
    else
        top->set_Ax(3);
    if (Vy > 0)
        top->set_Ay(-3);
    else
        top->set_Ay(3);


    std::cout << top->get_x() << " " << top->get_y() << " before shoot" << std::endl;
    //top->move();
    move(top);
    std::cout << top->get_x() << " " << top->get_y() << " after shoot" << std::endl;

}

void Game::move(Ball *ball) {
    float x, y;
    while (int(ball->get_Vx()) != 0 or int(ball->get_Vy()) != 0) {
        if (int(ball->get_Vx()) != 0) {
            x = (ball->get_Ax() / 8) + (ball->get_Vx() / 2) + ball->get_x();
            ball->set_x(x);
            ball->set_Vx(ball->get_Vx() + (ball->get_Ax() / 2));

        }
        if (int(ball->get_Vy()) != 0) {
            y = (ball->get_Ay() / 8) + (ball->get_Vy() / 2) + ball->get_y();
            ball->set_y(y);
            ball->set_Vy(ball->get_Vy() + (ball->get_Ay() / 2));

        }

        check();
        this->render->renderer(this->get_balls());
        std::cout << "x = " << int(ball->get_x()) << "\t\ty = " << int(ball->get_y()) << "\t\tVx = "
                  << int(ball->get_Vx())
                  << "\t\tVy = " << int(ball->get_Vy()) << "\t\tAx = " << ball->get_Ax() << "\t\tAy = "
                  << ball->get_Ay() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void Game::check() {
    Ball *toop1, *toop2;
    float x, y, a, b, delta_x, delta_y, teta;
    for (int i = 0; i < 17; i++) {
        toop1 = get_balls()[i];
        x = toop1->get_x();
        y = toop1->get_y();

        if (toop1->get_x() > 1220) {
            if (toop1->get_Vx() > 0) {
                toop1->set_Ax(-toop1->get_Ax());
                //toop1->set_Ay(-toop1->get_Ay());
                toop1->set_Vx(-toop1->get_Vx() * 2 / 3);
                toop1->set_Vy(toop1->get_Vy() * 2 / 3);
            }
        }
        if (toop1->get_x() < 35) {
            if (toop1->get_Vx() < 0) {
                toop1->set_Ax(-toop1->get_Ax());
                //toop1->set_Ay(-toop1->get_Ay());
                toop1->set_Vx(-toop1->get_Vx() * 2 / 3);
                toop1->set_Vy(toop1->get_Vy() * 2 / 3);

            }
        }
        if (toop1->get_y() > 615) {
            if (toop1->get_Vy() > 0) {
                //toop1->set_Ax(-toop1->get_Ax());
                toop1->set_Ay(-toop1->get_Ay());
                toop1->set_Vx(toop1->get_Vx() * 2 / 3);
                toop1->set_Vy(-toop1->get_Vy() * 2 / 3);
            }
        }
        if (toop1->get_y() < 35) {
            if (toop1->get_Vy() < 0) {
                //toop1->set_Ax(-toop1->get_Ax());
                toop1->set_Ay(-toop1->get_Ay());
                toop1->set_Vx(toop1->get_Vx() * 2 / 3);
                toop1->set_Vy(-toop1->get_Vy() * 2 / 3);
            }
        }
        for (int j = i + 1; j < 17; j++) {
            toop2 = get_balls()[j];
            a = toop2->get_x();
            b = toop2->get_y();
            delta_x = x - a;
            delta_y = y - b;
            if (abs(delta_x) < 15 and abs(delta_y) < 15) {
                teta = atan(delta_y / delta_x);
                
            }

        }
    }
}