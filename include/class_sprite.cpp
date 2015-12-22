#include "class_sprite.h"

#include <iostream>
#include <cstdlib>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Sprite::Sprite( Coord pos, Coord size )
{

    HitBox.pos = pos;
    HitBox.bounds = size;

}

Sprite::Sprite()
{

    tex = 0;
    HitBox.pos = Coord( 1, 1 );
    HitBox.bounds = Coord( 1, 1 );

}

void Sprite::SetPos( Coord pos )
{

    HitBox.pos = pos;

}

void Sprite::SetSize( Coord size )
{

    HitBox.bounds = size;

}

void Sprite::LoadTexture( const char *filepath, int w, int h )
{

    int n = 4;

    unsigned char *data = stbi_load( filepath, &w, &h, &n, STBI_rgb_alpha );
    tex = 0;
    
    if( data == nullptr )
    {

        std::printf( "Error: %s not found.", filepath );
    
    }else
    {

        glGenTextures( 1, &tex );
        glBindTexture( GL_TEXTURE_2D, tex );

        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data );

        free(data);

    }

}

template< class T >
bool Sprite::operator==( T val )
{

    if( tex == val )
    {
        return true;
    }

    return false;

}

std::vector<float> Sprite::GetCoords()
{

    std::vector<float> temp;
    return temp;

}

void Sprite::BindTex()
{

    glBindTexture( GL_TEXTURE_2D, tex );

}

void Sprite::PassTexture( GLuint tex )
{

    this->tex = tex;

}

GLuint Sprite::GetTexture()
{

    return tex;

}
