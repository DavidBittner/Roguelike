#include <cstdlib>
#include <iostream>

#include <chrono>
#include <thread>

#include <GL/glew.h>

#include <thread>
#include <chrono>

#include "include/class_engine.h"
#include "include/class_player.h"

int main()
{

    printf( "Starting program...\n" );
    GetEngine();

    while( !GetEngine().GetTerm() )
    {

        GetEngine().Fire(); 

    }

}
