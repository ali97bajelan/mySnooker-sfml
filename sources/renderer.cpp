
#include "../headers/renderer.h"
#include <iostream>
/*
void renderer(RenderWindow *window, Game *game) {
    Ball *ball = game->get_ball();
    CircleShape shape;
    shape.setRadius(10);
    shape.setPosition(ball->get_x(), ball->get_y());
    shape.setOrigin(5, 5);
    shape.setFillColor(Color::Blue);
    window->draw(shape);
}
 */
void renderer(RenderWindow *window,Ball **balls){
    CircleShape shape[10];
    CircleShape cir;
    for (int i = 0; i <10 ; i++) {
        float x=balls[i]->get_x();
        float y=balls[i]->get_y();
        //std::cout<<x<<" "<<y<<std::endl;
        shape[i].setRadius(10);
        shape[i].setPosition(x,y);
        shape[i].setOrigin(5,5);
        Color color=balls[i]->get_color();
        shape[i].setFillColor(color);
    }




    Texture image;
    image.loadFromFile("Picture/Table.jpg");

    Sprite background(image);

    window->clear();
    window->draw(background);
    window->draw(cir);
    //window->draw(shape[0]);

    for (int j = 0; j <10 ; j++) {
        window->draw(shape[j]);
        //std::cout<<"f";
    }

    window->display();
}
//#endif //MYSNOOKER_RENDERER_H
