#include "class_engine.h"
#include <iostream>
#include <cstdlib>

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
