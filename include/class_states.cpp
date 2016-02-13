#include <GL/glew.h>

#include <cstdlib>
#include <iostream>

#include "class_states.h"
#include "class_engine.h"

#include "class_keyboard.h"

#include "funcs_helpers.h"

/*
Init
--------------------------
*/

State *Init::exec()
{

    printf("Initializing...\n" );

    int WIND_WIDTH = 800, WIND_HEIGHT = 600;
    int MAP_SIZE = 64;

    GetKeyboard();

    glfwInit();
    Engine::window = glfwCreateWindow( WIND_WIDTH, WIND_HEIGHT, "Roguelike", nullptr, nullptr );
    glfwMakeContextCurrent( Engine::window );

    glfwSwapInterval( 1 );

    glfwSetKeyCallback( Engine::window, KeyHelper );
    glfwSetWindowSizeCallback( Engine::window, ReshapeHelper ); 

    ReshapeHelper( Engine::window, WIND_WIDTH, WIND_HEIGHT );

    glewInit();

    Engine::stateProc.InitializePlayer();
    initMap = new Map( MAP_SIZE );

    return &Engine::statePoll; 

}

/*
Poll
--------------------------
*/

State *Poll::exec()
{

    GetEngine().start();
    glfwPollEvents();

    mainCont.KeyOps();

    GetKeyboard().ResetKeys();

    if( glfwWindowShouldClose( glfwGetCurrentContext() ) )
    {

        return &Engine::stateStop;

    }else
    {

        return &Engine::stateProc;

    }

    //who knows lul
    return nullptr;

}

/*
Process
--------------------------
*/

State *Process::exec()
{

    mainCont.Move();

    return &Engine::stateRend;

}

void Process::InitializePlayer()
{

    ply = new Player();

}

/*
Render
--------------------------
*/

Coord *Render::perspective = new Coord( 0.0f, 0.0f );

void Render::SetPerspective( Coord *newPersp )
{

    perspective = newPersp;

}

State *Render::exec()
{

    glClear( GL_COLOR_BUFFER_BIT );
    glLoadIdentity();

    glTranslatef( -perspective->x, -perspective->y, -1.0f );

    renderMap.Draw( Rect( Coord( 0, 0 ), Coord( 5, 5 ) ) );
    mainCont.Draw();

    glfwSwapBuffers( glfwGetCurrentContext() );

    GetEngine().end();
    GetEngine().cap();

    return &Engine::statePoll;

}

/*
Stop
--------------------------
*/

State *Stop::exec()
{

    printf( "Terminating...\n" );

    glfwTerminate();

    return nullptr;

}
