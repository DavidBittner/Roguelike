#include "class_sprite.h"

#include <GLFW/glfw3.h>
#include <fstream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

void Sprite::LoadTex( const char *filename, int w, int h, int xam, int yam )
{

    this->xam = xam;
    this->yam = yam;

    loaded = true;

    int n = 4;

    unsigned char *data = stbi_load( filename, &w, &h, &n, STBI_rgb_alpha );

    if( data == nullptr )
    {

        printf( "Could not load texture: %s\n", filename );
        tex = 0;

    }else
    {

        printf( "Loaded texture: %s\n", filename );

        glGenTextures( 1, &tex );
        glBindTexture( GL_TEXTURE_2D, tex );

        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data );
        printf( "Tex buffer is:%d.\n", tex );

    }
    free( data );

}

Rect Sprite::GetTexCoords( int num )
{

    if( xam == 1 && yam == 1 )
    {

        return Rect( Coord( 0.0f, 0.0f ), Coord( 1.0f, 1.0f ) );

    }

    float xwid = 1.0f/xam;
    float ywid = 1.0f/xam;

    float xpos = num%xam;
    float ypos = int(floor(num/xam));

    Rect returnRect( Coord( xpos, ypos ), Coord( xwid, ywid ) );
    return returnRect;

}

void Sprite::Draw( float x, float y, float w, float h, float ang )
{

    glPushMatrix();

    glTranslatef( x, y, 0.0f );
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
    
        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,

        0.0f, 1.0f,
        0.0f, 0.0f,
        1.0f, 0.0f

    };

    if( loaded )
    {
    
        glBindTexture( GL_TEXTURE_2D, tex );

    }

    glVertexPointer( 2, GL_DOUBLE, 0, verts );
    glTexCoordPointer( 2, GL_DOUBLE, 0, texVerts );

    glDrawArrays( GL_TRIANGLES, 0, 6 );

    glBindTexture( GL_TEXTURE_2D, 0 );

    glPopMatrix();

}

void Sprite::Draw( int num, float x, float y, float w, float h, float ang )
{

    glPushMatrix();

    glTranslatef( x, y, 0.0f );
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

    Rect tempRect = GetTexCoords( num );

    double texVerts[] = 
    {
    
        tempRect.pos.x, tempRect.pos.y+tempRect.bnd.y,
        tempRect.pos.x+tempRect.bnd.x, tempRect.pos.y+tempRect.bnd.y,
        tempRect.pos.x+tempRect.bnd.x, tempRect.pos.y,

        tempRect.pos.x, tempRect.pos.y+tempRect.bnd.y,
        tempRect.pos.x, tempRect.pos.y,
        tempRect.pos.x+tempRect.bnd.x, tempRect.pos.y

    };

    if( loaded )
    {
    
        glBindTexture( GL_TEXTURE_2D, tex );

    }

    glVertexPointer( 2, GL_DOUBLE, 0, verts );
    glTexCoordPointer( 2, GL_DOUBLE, 0, texVerts );

    glDrawArrays( GL_TRIANGLES, 0, 6 );

    glBindTexture( GL_TEXTURE_2D, 0 );

    glPopMatrix();

}

void Sprite::Terminate()
{

    glDeleteTextures( 1, &tex );

}
