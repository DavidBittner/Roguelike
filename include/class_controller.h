#pragma once

#include "struct_rect.h"

#include <vector>

class Controller
{

    public: 
        Controller();

        virtual void KeyOps() = 0;
        virtual void Move() = 0;
        
        void Draw();

    protected:
        Rect HitBox;
        float ang;
        
    private:
        static int count;
        static std::vector<float> verts;
        static std::vector<float> colors;

};


