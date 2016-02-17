#include "class_engine.h"
#include <iostream>
#include <cstdlib>
#include <thread>

Init    Engine::stateInit;
Poll    Engine::statePoll;
Process Engine::stateProc;
Render  Engine::stateRend;
Stop    Engine::stateStop;

GLFWwindow *Engine::window;

Engine &GetEngine()
{

    static Engine *eng = new Engine();
    return *eng;

}

Engine::Engine()
{

    curState = &stateInit;

    termed = false;

}

bool Engine::GetTerm()
{

    return termed;

}

void Engine::Fire()
{

    curState = curState->exec();

    if( curState == nullptr )
    {

        termed = true;

    }

}

void Engine::start()
{

    stime = glfwGetTime();

}

void Engine::end()
{

    etime = glfwGetTime();

}

void Engine::cap()
{

    int time = ( (etime-stime) - (1000.0f/FRAMES_PER_SECOND ) );

    std::this_thread::sleep_for( std::chrono::milliseconds( time ) );

}

float Engine::GetAsp( int asp )
{

    switch( asp )
    {

        case TILE_SIZE:
        {

            return tileSize;

        }
        case MAP_SIZE:
        {

            return mapSize;

        }

    }

    return 0.0f;

}

template <class T>
void Engine::SetAsp( int asp, T setter )
{

    switch( asp )
    {

        case TILE_SIZE:
        {

            tileSize = setter;
            break;

        }

    }

}

void Engine::SetAsp( int asp, int setter )
{

    switch( asp )
    {

        case MAP_SIZE:
        {

            mapSize = setter;
            break;

        }

    }

}
