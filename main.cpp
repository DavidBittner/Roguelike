#include <cstdlib>
#include <iostream>

#include <chrono>
#include <thread>

#include "include/class_engine.h"

int main()
{
    
    printf( "Revving the engine...\n" );
    GetEngine();

    int tick = 0;

    while( tick < 200 )
    {

        GetEngine().Fire(); 
        tick++;

        std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );

    }

}
