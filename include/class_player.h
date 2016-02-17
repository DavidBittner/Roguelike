#pragma once

#include "class_controller.h"
#include "struct_coord.h"
#include "struct_rect.h"
#include "class_map.h"

class Player : public Controller
{

    public:
        Player();

        void Draw();
        void Move();
        void KeyOps();

        Coord *GetPersp(){ return &pos; }

    private:
        int level = 0;

        Coord pos;
        Coord targPos;

        Rect hitBox;

        Sprite selfSprite;

        Map mapInstance;

        const float movSpeed = 20.0f;

};
