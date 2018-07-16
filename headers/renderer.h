//
// Created by ali on 7/14/18.
//

#ifndef MYSNOOKER_RENDERER_H
#define MYSNOOKER_RENDERER_H

#include <SFML/Graphics.hpp>
#include "ball.h"
class Rendering{
public:
  Rendering();
  void renderer(RenderWindow *window,Ball **balls);

private:
    CircleShape shape[17];
    Texture pic[18];
    Sprite background;
};
#endif //MYSNOOKER_RENDERER_H
