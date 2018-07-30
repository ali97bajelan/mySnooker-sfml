
#include "../headers/renderer.h"
#include <iostream>

Rendering::Rendering(RenderWindow *window) {
    for (int i = 0; i < 17; i++) {
        if (i == 0)
            this->pic[i].loadFromFile("Picture/900/white.png");
        if (i > 0 and i < 11)
            this->pic[i].loadFromFile("Picture/900/red.png");
        if (i == 11)
            this->pic[i].loadFromFile("Picture/900/blue.png");
        if (i == 12)
            this->pic[i].loadFromFile("Picture/900/black(croped).png");
        if (i == 13)
            this->pic[i].loadFromFile("Picture/900/yellow2.png");
        if (i == 14)
            this->pic[i].loadFromFile("Picture/900/green.png");
        if (i == 15)
            this->pic[i].loadFromFile("Picture/900/purple.png");
        if (i == 16)
            this->pic[i].loadFromFile("Picture/900/orange.png");
        this->shape[i].setRadius(11);
        this->shape[i].setTexture(&this->pic[i]);
    }
    this->pic[17].loadFromFile("Picture/Table.jpg");
    this->pic[17].setSmooth(true);
    this->background.setTexture(this->pic[17]);
    this->window = window;

    this->result.setPosition(200,200);
    this->result.setFillColor(Color::Black);
    this->result.setCharacterSize(10);
    //this->result.setString(std::to_string())
}

void Rendering::renderer(Ball **balls,std::string result) {

    for (int i = 0; i < 17; i++) {
        float x = balls[i]->get_x();
        float y = balls[i]->get_y();
        this->shape[i].setPosition(x, y);
    }
    this->result.setString(result);
    Font font ;
    font.loadFromFile("Picture/900/arial.ttf");
    this->result.setFont(font);
    //this->result.setStyle(sf::Text::Bold);

    this->window->clear();
    this->window->draw(this->background);

    for (int j = 0; j < 17; j++) {
        this->window->draw(this->shape[j]);
    }
    this->window->draw(this->result);
    this->window->display();
}

int Rendering::get() {
    return this->shape[0].getPosition().x;
}