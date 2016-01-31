#pragma once

#include <vector>

#include <GLFW/glfw3.h>

#include "class_sprite.h"

class Controller
{

    public:
        Controller();

        void Terminate();

        void RunInit();

        virtual void Draw();
        virtual void Move();
        virtual void KeyOps();

        std::vector<Controller*> &getChildren();

};
