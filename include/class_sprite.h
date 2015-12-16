#pragma once

#include "struct_rect.h"
#include "struct_coord.h"
#include "struct_rect.h"

#include <vector>
#include <GLFW/glfw3.h>

class Sprite
{

    public:
        Sprite( Coord pos, Coord size );
        Sprite();

        float *TexCoords();
        std::vector<float> GetCoords();

        void SetPos( Coord pos );
        void SetSize( Coord size );
        void SetNum( int num );

        void BindTex();

        void LoadTexture( const char *filepath, int w, int h );
        void PassTexture( GLuint tex );

        GLuint GetTexture();
        
        template< class T >
        bool operator==( T val );

    private:
        bool isSpriteSheet;
        int texNum;

        GLuint tex;

        Coord pos;        
        Rect HitBox;
        float ang;

};
