#include "headers/game.h"
#include "headers/ball.h"

#include "headers/renderer.h"
#include "headers/network.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


int main() {
    RenderWindow window;
    Game *game;
    Rendering render;
    //Game *game = new Game(600, 400);
    game = new Game(1280, 680);
    //Resource *resource = new Resource(game);
    //sf::RenderWindow window(sf::VideoMode(600, 400), "My Snooker");
    window.create(VideoMode(1280, 680), "My Snooker");

    cout<<"f";
    Event event;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == Keyboard::D){
                    game->shoot(10,45,0);
                    //game->get_balls()[0]->
                }
            //game->shoot(1, 4, 12, 0, 0);
            //cout<<game->get_ball()->get_y()<<" "<<game->get_ball()->get_x()<<endl;
            //}
            //if (event.type==sf::Event::MouseMoved){
            //std::cout<<sf::Mouse::getPosition(window).x<<" "<<sf::Mouse::getPosition(window).y<<std::endl;

            //}
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
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
        }
        //cout<<"a"<<endl;
        //this_thread::sleep_for(chrono::milliseconds(40));
        window.clear();
        render.renderer(&window, game->get_balls());
        //window.draw(image);
        window.display();
    }
}

void create() {

}