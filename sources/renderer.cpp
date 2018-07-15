
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
    CircleShape shape[17];
    Texture pic[17];

    for (int i = 0; i <17 ; i++) {
        float x=balls[i]->get_x();
        float y=balls[i]->get_y();
        std::string color=balls[i]->get_color();
        if(color=="white" or color=="orange")
            pic[i].loadFromFile("Picture/"+color+".jpg");
        else
            pic[i].loadFromFile("Picture/"+color+".png");
        //pic[i].setSmooth(true);
        shape[i].setTexture(&pic[i]);

        shape[i].setRadius(12);
        shape[i].setPosition(x,y);
        //shape[i].setOrigin(5,5);

    }




    Texture image;
    image.loadFromFile("Picture/Table.jpg");
    image.setSmooth(true);
    Sprite background(image);

    window->clear();
    window->draw(background);

    for (int j = 0; j <17 ; j++) {
        window->draw(shape[j]);
        //std::cout<<"f";
    }


    window->display();
}
//#endif //MYSNOOKER_RENDERER_H
