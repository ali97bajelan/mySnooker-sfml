
#include "../headers/renderer.h"
#include <iostream>

Rendering::Rendering() {
    for (int i = 0; i < 17; i++) {
        if (i == 0)
            this->pic[i].loadFromFile("Picture/white.jpg");
        if (i > 0 and i < 11)
            this->pic[i].loadFromFile("Picture/red.png");
        if (i == 11)
            this->pic[i].loadFromFile("Picture/blue.png");
        if (i == 12)
            this->pic[i].loadFromFile("Picture/black.png");
        if (i == 13)
            this->pic[i].loadFromFile("Picture/yellow.png");
        if (i == 14)
            this->pic[i].loadFromFile("Picture/green.png");
        if (i == 15)
            this->pic[i].loadFromFile("Picture/purple.png");
        if (i == 16)
            this->pic[i].loadFromFile("Picture/orange.jpg");
        this->shape[i].setRadius(12);
        this->shape[i].setTexture(&this->pic[i]);
    }
    this->pic[17].loadFromFile("Picture/Table.jpg");
    this->pic[17].setSmooth(true);
    this->background.setTexture(this->pic[17]);

}

void Rendering::renderer(RenderWindow *window, Ball **balls) {

    for (int i = 0; i < 17; i++) {
        float x = balls[i]->get_x();
        float y = balls[i]->get_y();
        this->shape[i].setPosition(x, y);
    }

    window->clear();
    window->draw(this->background);

    for (int j = 0; j < 17; j++) {
        window->draw(this->shape[j]);
    }

    window->display();
}
