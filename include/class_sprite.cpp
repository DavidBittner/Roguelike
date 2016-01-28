#include "class_sprite.h"

#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

void Sprite::LoadTex( const char *filename, int w, int h )
{

    int n = 4;

    unsigned char *data = stbi_load( filename, &w, &h, &n, STBI_rgb_alpha );
    GLuint texture = 0;

    if( data == nullptr )
    {

        printf( "Could not load texture: %s\n", filename );
        tex = 0;

    }else
    {

        printf( "Loaded texture: %s\n", filename );

        glGenTextures( 1, &texture );
        glBindTexture( GL_TEXTURE_2D, texture );

        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data );

    }
    free( data );

}

void Sprite::Draw( float x, float y, float w, float h, float ang )
{

    glTranslatef( x, y, -1.0f );
    glRotatef( ang, false, false, true );

    double verts[] = 
    {
        -(w/2.0), -(h/2.0),
         (w/2.0), -(h/2.0),
         (w/2.0),  (h/2.0),

        -(w/2.0), -(h/2.0),
        -(w/2.0),  (h/2.0),
         (w/2.0),  (h/2.0)
    };

    double texVerts[] = 
    {
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,

        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f
    };

    glBindTexture( GL_TEXTURE_2D, tex );

    glVertexPointer( 2, GL_FLOAT, 0, verts );
    glTexCoordPointer( 2, GL_FLOAT, 0, texVerts );

    glDrawArrays( GL_TRIANGLES, 0, 4 );

}

void Sprite::Terminate()
{

    glDeleteTextures( 1, &tex );

}
