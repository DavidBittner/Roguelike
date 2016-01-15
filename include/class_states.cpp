#include <cstdlib>
#include <iostream>

#include "class_states.h"
#include "class_engine.h"

/*
Init
--------------------------
*/

State *Init::exec()
{

    printf("Initalizing the polls...\n" );

    return GetEngine().GetState( "poll" ); 

}

/*
Poll
--------------------------
*/

State *Poll::exec()
{

    printf( "Polling the users...\n" );

    return GetEngine().GetState( "proc" );

}

/*
Process
--------------------------
*/

State *Process::exec()
{

    printf( "Processing the data (reticulating splines)...\n" );

    return GetEngine().GetState( "rend" );

}

/*
Render
--------------------------
*/

State *Render::exec()
{

    printf( "Rendering stuff...\n" );

    return GetEngine().GetState( "poll" );

}

/*
Stop
--------------------------
*/

State *Stop::exec()
{

    printf( "I know who Iwant to take me home...\n" );

    return nullptr;

}
