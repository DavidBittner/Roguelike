#include <cstdlib>
#include <iostream>

#include "class_states.h"

/*
Init
--------------------------
*/

void Init::exec()
{

    printf("Initalizing the polls...\n" );

}

/*
Poll
--------------------------
*/

void Poll::exec()
{

    printf( "Polling the users...\n" );

}

/*
Process
--------------------------
*/

void Process::exec()
{

    printf( "Processing the data (reticulating splines)...\n" );

}

/*
Render
--------------------------
*/

void Render::exec()
{

    printf( "Rendering stuff...\n" );

}

/*
Stop
--------------------------
*/

void Stop::exec()
{

    printf( "I know who Iwant to take me home...\n" );

}
