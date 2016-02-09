#include "class_sprite.h"

#include <GLFW/glfw3.h>
#include <fstream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

std::string Sprite::genDataName( const char *filename )
{

    int dashPos = 0;
    int extPos = 0;

    std::string temp( filename );

    for( unsigned i = 0; i < temp.size(); i++ )
    {

        if( temp[i] == '/' )
        {

            dashPos = i;

        }
        if( temp[i] == '.' )
        {
        
            extPos = i;

        }

    }

    temp.insert( dashPos+1, "." );

    printf( "%s\n", temp.c_str() );

    return temp;

}

void Sprite::LoadTex( const char *filename, int w, int h )
{

    loaded = true;

    int n = 4;

    std::ifstream imgData( genDataName( filename ) );
    
    if( imgData.good() )
    {

        std::string temp;

        std::getline( imgData, temp );
        xam = std::atoi( temp.c_str() );
        std::getline( imgData, temp );
        yam = std::atoi( temp.c_str() );

        printf( "%s\n", temp.c_str() );

    }

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

void Sprite::Terminate()
{

    glDeleteTextures( 1, &tex );

}
