#ifndef CLASS_CONTROL
#define CLASS_CONTROL

#include "struct_rect.cpp"

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

};

void Controller::Draw()
{

    this->verts.push_back( HitBox.pos.x );

}

#endif
