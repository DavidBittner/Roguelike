#include <iostream>
#include <GLFW/glfw3.h>

#include "class_engine.h"
#include "class_player.h"

ENGINE &ENGINE_GET()
{

    ENGINE *eng = new ENGINE();
    return *eng;

}

void glfwReshape( GLFWwindow *wind, int width, int height )
{

    ENGINE_GET().Reshape( wind, width, height );

}

ENGINE::ENGINE()
{

    std::printf( "ENGINE CONSTRUCTION...\n" );

}

void ENGINE::Init( int WIND_WID, int WIND_HEI )
{

    std::printf( "ENGINE INITILIZATION...\n" );

    if( glfwInit() != GL_TRUE )
    {

        std::printf( "Failed to initalize GLFW, terminating.\n" );
        glfwTerminate();

    }

    wind = glfwCreateWindow( WIND_WID, WIND_HEI, "Roguelike", nullptr, nullptr );
    glfwMakeContextCurrent( wind );

    Reshape( wind, WIND_WID, WIND_HEI );
    glfwSetWindowSizeCallback( wind, glfwReshape );
    this->WIND_WID = WIND_WID; 
    this->WIND_HEI = WIND_HEI;

    Ply = new Player();

    Poll();

}

void ENGINE::Poll()
{

    bool canceled = false;

    glfwPollEvents();
    canceled = glfwWindowShouldClose( wind );

    if( canceled )
    {

        Stop();

    }else
    {

        Process();

    }

}

void ENGINE::Process()
{

    Ply->Move();

    Render();

}

void ENGINE::Render()
{

    glClear( GL_COLOR_BUFFER_BIT );
    glLoadIdentity();
    glTranslatef( 0.0f, 0.0f, -1.0f );

    Ply->Draw();

    glfwSwapBuffers( wind );

    Poll();

}

void ENGINE::Stop()
{

    std::printf( "ENGINE TERMINATING...\n" );

    glfwTerminate();

}

void ENGINE::Reshape( GLFWwindow *WIND, int width, int height )
{

    glViewport( 0, 0, (GLsizei)width, (GLsizei)height );
    glMatrixMode( GL_PROJECTION );

    glLoadIdentity();
    glOrtho( -width/2.0, width/2.0, -height/2.0, height/2.0, 1.0f, 2.0f );

    glMatrixMode( GL_MODELVIEW );

}
