#pragma once

#include "struct_rect.h"

#include <string>
#include <GLFW/glfw3.h>

class Sprite
{

    public:
        void LoadTex( const char *filename, int w, int h, int xam, int yam );
        void Draw( float x, float y, float w, float h, float ang );
        void Draw( int num, float x, float y, float w, float h, float ang );

        void Terminate();

    private:
        Rect GetTexCoords( int num );

        GLuint tex;
        bool loaded;

        int xam, yam;

};
