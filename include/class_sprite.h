#pragma once

#include <GLFW/glfw3.h>

class Sprite
{

    public:
        float *TexCoords();

        void LoadTexture( const char *filepath );
        void PassTexture( GLuint tex );

    private:
        GLuint tex;

}
