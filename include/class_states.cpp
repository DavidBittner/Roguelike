#include <cstdlib>
#include <iostream>

#include <GLFW/glfw3.h>

#include "class_states.h"
#include "class_engine.h"

/*
Init
--------------------------
*/

State *Init::exec()
{

    printf("Initializing...\n" );

    int WIND_WIDTH = 800, WIND_HEIGHT = 600;

    glfwInit();
    Engine::window = glfwCreateWindow( WIND_WIDTH, WIND_HEIGHT, "Roguelike", nullptr, nullptr );
    glfwMakeContextCurrent( Engine::window );

    return &Engine::statePoll; 

}

/*
Poll
--------------------------
*/

State *Poll::exec()
{

    glfwPollEvents();

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

    return &Engine::stateRend;

}

/*
Render
--------------------------
*/

State *Render::exec()
{

    glfwSwapBuffers( glfwGetCurrentContext() );

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
