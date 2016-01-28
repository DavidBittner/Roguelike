#pragma once

#include <vector>

#include <GLFW/glfw3.h>

#include "class_sprite.h"

class Controller
{

    public:
        Controller();

        void Terminate();

        void Draw();
        virtual void Move();

    protected:
        static std::vector<Controller*> childControls; 

};
