#pragma once

#include "struct_coord.h"

#include <iostream>
#include <vector>

class MapGenerator
{

    public:
        MapGenerator( int size );
        int **GenMap();

    private:
        
        int CheckNeighbors( int **map, int checkNum, int inx, int iny );
        bool isIn( std::vector<Coord*> list, Coord check );

        int MAP_SIZE;

};

