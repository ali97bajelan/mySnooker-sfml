#include "headers/game.h"
#include "headers/ball.h"
#include "headers/renderer.h"
#include "headers/network.h"

#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


int main() {
    RenderWindow window;
    Game *game;
    Rendering *render=new Rendering();
    //Game *game = new Game(600, 400);
    game = new Game(1280, 680);
    //Resource *resource = new Resource(game);
    //sf::RenderWindow window(sf::VideoMode(600, 400), "My Snooker");
    window.create(VideoMode(1280, 680), "My Snooker");
    //window.setFramerateLimit(100);
    Event event;

    float teta,first_x, first_y,end_x,end_y,delta_x,delta_y = 0;
    int count =0 ;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == Keyboard::D) {
                    game->shoot(20, teta, 0);
                    //game->get_balls()[0]->
                }
                //game->shoot(1, 4, 12, 0, 0);
                //cout<<game->get_ball()->get_y()<<" "<<game->get_ball()->get_x()<<endl;
                //}
                //if (event.type==sf::Event::MouseMoved){
                //std::cout<<sf::Mouse::getPosition(window).x<<" "<<sf::Mouse::getPosition(window).y<<std::endl;

                //}
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    count++;
                    if (count % 2 == 1) {
                         first_x = Mouse::getPosition().x;
                         first_y = Mouse::getPosition().y;
                    } else {
                         end_x = Mouse::getPosition().x;
                         end_y = Mouse::getPosition().y;
                         delta_x = end_x - first_x;
                         delta_y = end_y - first_y;
                        cout << first_x << " " << first_y << endl;
                        cout << end_x << " " << end_y << endl;
                        cout << delta_x << " " << delta_y << endl;
                        double t=delta_y/delta_x;
                        teta=atan(t);

                        cout<<"degree"<<teta<<" "<<t<<endl;
                    }


                    cout << "zad " << count << endl;


                }
            }
            //game->shoot(1, 2, 3, 1, 1);
            /*
            Ball *ball=game->get_balls();
            ball->set_Ay(4);
            ball->set_Ax(4);
            ball->set_Vx(10);
            ball->set_Vy(10);
            ball->move(&window);
            cout << game->get_ball()->get_y() << " " << game->get_ball()->get_x() << endl;
        */
        }

        //cout<<"a"<<endl;
        //this_thread::sleep_for(chrono::milliseconds(40));
        //window.clear();
        render->renderer(&window, game->get_balls());
        //cout<<render->get()<<"pos"<<endl;
        //window.draw(image);
        //window.display();
    }
}