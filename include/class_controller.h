#pragma once

#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Controller
{

    public:
        Controller();

        void Draw();
        void Terminate();

        virtual void Move() = 0;

    private:
        static std::vector<GLuint> objectBuffers;

};
