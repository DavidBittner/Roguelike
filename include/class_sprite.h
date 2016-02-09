#pragma once

#include <string>
#include <GLFW/glfw3.h>

class Sprite
{

    public:
        void LoadTex( const char *filename, int w, int h );
        void Draw( float x, float y, float w, float h, float ang );
        void Draw( int num, float x, float y, float w, float h, float ang );

        void Terminate();

    private:
        GLuint tex;
        bool loaded;

        int xam, yam;

        std::string genDataName( const char *filename );

};
