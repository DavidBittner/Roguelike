#pragma once

#include "class_controller.h"

class Player : public Controller
{

    public:
        Player();

        void Draw();
        void Move();

    private:
       float x, y;

       Sprite selfSprite;

};
