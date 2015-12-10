#pragma once

#include "struct_coord.h"

struct ENG_CONFIG
{

    ENG_CONFIG( int TILE_SIZE, Coord MAP_SIZE );

    int TILE_SIZE;
    Coord MAP_SIZE;

};

ENG_CONFIG& GET_CONFIG();

