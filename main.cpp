#include "headers/game.h"
#include "headers/ball.h"
#include "headers/renderer.h"
#include "headers/network.h"

#define pi 3.14159265

#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


int main() {
    RenderWindow window;
    window.create(VideoMode(1280, 680), "My SnokkkkkkkPoker");

    Rendering *render = new Rendering(&window);
    cout<<"fuck"<<endl;
    Game *game = new Game(1280, 680, render);
    cout<<"fuck"<<endl;
    //Resource *resource = new Resource(game);
    //window.setFramerateLimit(100);
    Event event;
    float teta = 0;
    float first_x, first_y, end_x, end_y, delta_x, delta_y = 0;
    int count = 0;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == Keyboard::O) {
                    game->shoot(40, teta, 0);
                }
                if (event.key.code == Keyboard::Right) {
                    game->shoot(40, 0, 0);
                }
                if (event.key.code == Keyboard::Down) {
                    game->shoot(40, pi / 2, 0);
                }
                if (event.key.code == Keyboard::Left) {
                    game->shoot(40, pi, 0);
                }
                if (event.key.code == Keyboard::Up) {
                    game->shoot(40, 3 * pi / 2, 0);
                }
                if (event.key.code == Keyboard::M) {
                    game->shoot(60, pi / 6, 0);
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    count++;
                    cout << "zad " << count << endl;

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
                        double t = delta_y / delta_x;
                        teta = atan(t);
                        cout << "degree= " << 180 * teta / pi << " " << t << endl;
                    }
                }
            }

        }
        //this_thread::sleep_for(chrono::milliseconds(40));
        render->renderer(game->get_balls());
    }
}