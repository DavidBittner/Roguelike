#include <cstdlib>
#include <iostream>

#include <chrono>
#include <thread>

#include "include/class_engine.h"

int main()
{
    
    printf( "Starting program...\n" );
    GetEngine();

    while( !GetEngine().GetTerm() )
    {

        GetEngine().Fire(); 

    }

}
