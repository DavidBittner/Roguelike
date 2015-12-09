#pragma once

#include "class_controller.h"
#include "struct_coord.h"

class Player: public Controller
{

    //Basic declarations for functions and the target aimpos;
    public:
        Player();

        void Move();
        void KeyOps();

    private:
        Coord tarPos;

};
