#include <iostream>
#include <GLFW/glfw3.h>

#include "class_engine.h"
#include "class_player.h"

ENGINE &ENGINE_GET()
{

    static ENGINE *eng = new ENGINE();
    return *eng;

}

void glfwReshape( GLFWwindow *wind, int width, int height )
{

    ENGINE_GET().Reshape( wind, width, height );

}

void glfwKeyFunc( GLFWwindow *wind, int key, int scancode, int action, int mods )
{

    ENGINE_GET().KeyFunc( wind, key, scancode, action, mods );

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
    glfwSetKeyCallback( wind, glfwKeyFunc );
    this->WIND_WID = WIND_WID; 
    this->WIND_HEI = WIND_HEI;

    Ply = new Player();
    keyStates = new bool[256];

    Poll();

}

void ENGINE::Poll()
{

    bool canceled = false;

    glfwPollEvents();

    Ply->KeyOps();

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

bool *ENGINE::GetKeyStates()
{

    return keyStates;

}

void ENGINE::Reshape( GLFWwindow *WIND, int width, int height )
{

    glViewport( 0, 0, (GLsizei)width, (GLsizei)height );
    glMatrixMode( GL_PROJECTION );

    glLoadIdentity();
    glOrtho( -width/2.0, width/2.0, -height/2.0, height/2.0, 1.0f, 2.0f );

    glMatrixMode( GL_MODELVIEW );

}

void ENGINE::KeyFunc( GLFWwindow *wind, int key, int scancode, int action, int mods )
{

    if( action == GLFW_PRESS )
    {

        keyStates[key] = true;

    }
    else if( action == GLFW_RELEASE )
    {

        keyStates[key] = false;

    }

}
