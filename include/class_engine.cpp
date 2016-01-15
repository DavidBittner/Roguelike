#include "class_engine.h"
#include <iostream>
#include <cstdlib>

Init    Engine::stateInit;
Poll    Engine::statePoll;
Process Engine::stateProc;
Render  Engine::stateRend;
Stop    Engine::stateStop;

Engine &GetEngine()
{

    static Engine *eng = new Engine();
    return *eng;

}

Engine::Engine()
{

    curState = GetState( "init" );

}

void Engine::Fire()
{

    curState = curState->exec();

}

State *Engine::GetState( std::string state )
{

    if( state == "init" )
    {

        return &stateInit;

    }else if( state == "poll" )
    {

        return &statePoll;

    }else if( state == "proc" )
    {

        return &stateProc;

    }else if( state == "rend" )
    {

        return &stateRend;

    }else if( state == "stop" )
    {

        return &stateStop;

    }

    printf( "Invalid state... returning nullptr.\n" );
    return nullptr;

}

