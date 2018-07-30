//
// Created by msd on 6/27/18.
//

#include "../headers/game.h"
#include <algorithm>
#include <thread>
#include <iostream>
#include <chrono>

#define pi 3.14159265

using namespace std;

Game::Game(int width, int height, Rendering *render) {
    this->width = width;
    this->height = height;
    this->score1 = 0;
    this->score2 = 0;
    this->red_color1 = true;
    this->red_color2 = true;

    this->render = render;
    this->balls = new Ball *[17];
    for (int i = 0; i < 17; ++i) {
        for (int j = 0; j <17 ; ++j) {
            this->colision[i][j]= false;
        }
    }
    balls[0] = new Ball(1100, 335, 0, 0, 0, "white");

    balls[1] = new Ball(150, 290, 0, 0, 1, "red");
    balls[2] = new Ball(150, 315, 0, 0, 1, "red");
    balls[3] = new Ball(150, 340, 0, 0, 1, "red");
    balls[4] = new Ball(150, 365, 0, 0, 1, "red");
    balls[5] = new Ball(170, 305, 0, 0, 1, "red");
    balls[6] = new Ball(170, 330, 0, 0, 1, "red");
    balls[7] = new Ball(170, 355, 0, 0, 1, "red");
    balls[8] = new Ball(190, 320, 0, 0, 1, "red");
    balls[9] = new Ball(190, 345, 0, 0, 1, "red");
    balls[10] = new Ball(210, 335, 0, 0, 1, "red");

    balls[11] = new Ball(630, 335, 0, 0, 5, "blue"); // 630-335
    balls[12] = new Ball(100, 335, 0, 0, 7, "black");
    balls[13] = new Ball(990, 220, 0, 0, 2, "yellow");
    balls[14] = new Ball(990, 420, 0, 0, 3, "green");
    balls[15] = new Ball(235, 335, 0, 0, 6, "purple");
    balls[16] = new Ball(990, 335, 0, 0, 4, "orange");
}

Ball **Game::get_balls() {
    return this->balls;
}
string Game::result() {
    return to_string(this->score1)+"  "+to_string(this->score2);
}
void Game::scores(Ball ball) {
    int turn = this->turn % 2;
    if (turn == 0) {
        if (ball.get_color() == "red") {
            if (this->red_color1) {
                this->score1 += 1;
                this->red_color1 = false;
            } else {
                this->score2 += 4;
            }
        } else {
            if (!this->red_color1) {
                this->score1 += ball.get_value();
                this->red_color1 = true;
            } else {
                this->score2 += max(ball.get_value(), 4);
            }
        }
    } else {
        if (ball.get_color() == "red") {
            if (this->red_color2) {
                this->score2 += 1;
                this->red_color2 = false;
            } else {
                this->score1 += 4;
            }
        } else {
            if (!this->red_color2) {
                this->score2 += ball.get_value();
                this->red_color2 = true;
            } else {
                this->score1 += max(ball.get_value(), 4);
            }
        }
    }
}

void Game::shoot(float speed, float degree, int turn) {
    this->turn = turn;
    float Vx = speed * cos(degree);
    float Vy = speed * sin(degree);
    std::cout << Vx << " " << Vy << std::endl;

    Ball *top = get_balls()[0];
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
    move();
    std::cout << top->get_x() << " " << top->get_y() << " after shoot" << std::endl;

}

void Game::move() {
    Ball **balls = this->get_balls();
    Ball *ball;
    float x, y;
    while (this->is_moving()) {
        for (int i = 0; i < 17; i++) {
            ball = balls[i];
            if (int(ball->get_Vx()) != 0) {
                x = (ball->get_Ax() / 8) + (ball->get_Vx() / 2) + ball->get_x();
                ball->set_x(x);
                ball->set_Vx(ball->get_Vx() + (ball->get_Ax() / 2));
              //  cout << ball->get_color() << "\tx = " << x << "\t\t Vx = " << int(ball->get_Vx());

            }
            if (int(ball->get_Vy()) != 0) {
                y = (ball->get_Ay() / 8) + (ball->get_Vy() / 2) + ball->get_y();
                ball->set_y(y);
                ball->set_Vy(ball->get_Vy() + (ball->get_Ay() / 2));
              //  cout << ball->get_color() << "\t\t y = " << y << "\t\t Vy = " << ball->get_Vy() << endl;
            }
        }
        check();
        this_thread::sleep_for(chrono::milliseconds(50));
        this->render->renderer(this->get_balls(),this->result());
        //mcout<<"shod"<<endl;
    }
    //while (int(ball->get_Vx()) != 0 or int(ball->get_Vy()) != 0) {
    /*

    std::cout << "x = " << int(ball->get_x()) << "\t\ty = " << int(ball->get_y()) << "\t\tVx = "
              << int(ball->get_Vx())
              << "\t\tVy = " << int(ball->get_Vy()) << "\t\tAx = " << ball->get_Ax() << "\t\tAy = "
              << ball->get_Ay() << std::endl;
*/
}

void Game::check() {
    Ball *toop1, *toop2;
    float x, y, a, b, delta_x, delta_y, delta_Vx, delta_Vy, teta, beta, Vx1, Vy1, Vx2, Vy2, cal1, cal2;
    for (int i = 0; i < 17; i++) {
        toop1 = get_balls()[i];
        x = toop1->get_x();
        y = toop1->get_y();
        Vx1 = toop1->get_Vx();
        Vy1 = toop1->get_Vy();

        // goal middle Top
        if (x > 620 and x < 640 and y < 12) {
            cout << endl << "Goool" << endl;
            toop1->goal();
            scores(*toop1);
        }
        // goal middle Bottom
        if (x > 620 and x < 640 and y > 630) {
            cout << endl << "Goool" << endl;
            toop1->goal();
            scores(*toop1);

        }
        // goal Top Left
        if (x < 30 and y < 30) {
            cout << endl << "Goool" << endl;
            toop1->goal();
            scores(*toop1);

        }

        // goal Bottom Left
        if (x < 35 and y > 620) {
            cout << endl << "Goool" << endl;
            toop1->goal();
            scores(*toop1);

        }
        // goal Bottom Right
        if (x > 1210 and y > 620) {
            cout << endl << "Goool" << endl;
            toop1->goal();
            scores(*toop1);

        }

        // goal Top Right
        if (x > 1210 and y < 30) {
            cout << endl << "Goool" << endl;
            toop1->goal();
            scores(*toop1);

        }
        if (x > 1220) {
            if (toop1->get_Vx() > 0) {

                toop1->set_Vx(-toop1->get_Vx() * 1 / 2);
                toop1->set_Vy(toop1->get_Vy() * 1 / 2);
            }
        }
        if (x < 35) {
            if (toop1->get_Vx() < 0) {

                toop1->set_Vx(-toop1->get_Vx() * 1 / 2);
                toop1->set_Vy(toop1->get_Vy() * 1 / 2);

            }
        }
        if (y > 615) {
            if (toop1->get_Vy() > 0) {

                toop1->set_Vx(toop1->get_Vx() * 1 / 2);
                toop1->set_Vy(-toop1->get_Vy() * 1 / 2);
            }
        }
        if (y < 35 and !(x > 620 and x < 640)) {
            if (toop1->get_Vy() < 0) {

                toop1->set_Vx(toop1->get_Vx() * 1 / 2);
                toop1->set_Vy(-toop1->get_Vy() * 1 / 2);
            }
        }
        for (int j = i + 1; j < 17; j++) {
            toop2 = get_balls()[j];
            a = toop2->get_x();
            b = toop2->get_y();
            Vx2 = toop2->get_Vx();
            Vy2 = toop2->get_Vy();
            delta_x = x - a;
            delta_y = y - b;
            delta_Vx = Vx1 - Vx2;
            delta_Vy = Vy1 - Vy2;
            if (abs(delta_x) < 20 and abs(delta_y) < 20) {
                if (this->colision[i][j])
                    continue;
                //cout << endl << "\t\tZARBE" << endl << "teta = " << 180 * teta / pi << "\t\t beta = " << 180 * beta / pi
                    // << endl;
                // testing rules
                this->colision[i][j]= true;
                this->colision[j][i]= true;
                cout << toop1->get_color() << "\t Vx = " << Vx1 << "\t Vy = " << Vy1 << endl;
                cout << toop2->get_color() << "\t Vx = " << Vx2 << "\t Vy = " << Vy2 << endl;

                cal1 = (delta_Vx * delta_x + delta_Vy * delta_y) / (delta_x * delta_x + delta_y * delta_y);
                //cal2=-delta_Vx*-delta_x+(-delta_Vy*)
                toop1->set_Vx(Vx1 - cal1 * delta_x);
                toop1->set_Vy(Vy1 - cal1 * delta_y);
                toop2->set_Vx(Vx2 + cal1 * delta_x);
                toop2->set_Vy(Vy2 + cal1 * delta_y);
                //toop2->set_Vy(Vy2 * sin((teta - beta) * pi / 180) + Vy1 * cos((teta - beta) * pi / 180));

                cout << "\t\t After BARKHORD" << endl;
                cout << toop1->get_color() << "\t Vx = " << toop1->get_Vx() << "\t Vy = " << toop1->get_Vy() << endl;
                cout << toop2->get_color() << "\t Vx = " << toop2->get_Vx() << "\t Vy = " << toop2->get_Vy() << endl;

            } else{
                this->colision[i][j]= false;
                this->colision[j][i]= false;

            }

        }
    }
}

bool Game::is_moving() {
    Ball **balls = get_balls();
    Ball *ball;
    float Vx, Vy;
    for (int i = 0; i < 17; i++) {
        ball = balls[i];
        Vx = ball->get_Vx();
        Vy = ball->get_Vy();
        if (int(Vx) != 0 or int(Vy) != 0)
            return true;
    }
    return false;
}