#include "class_map.h"

#include <iostream>
#include <vector>

std::vector<int**> *Map::map;

void Map::ForceInit()
{

    map = new std::vector<int**>;

}

Map::Map( int size )
{

    MAP_SIZE = size;

    ForceInit();
    map->push_back( new int*[MAP_SIZE] );

    for( int i = 0; i < MAP_SIZE; i++ )
    {

        map->at(0)[i] = new int[MAP_SIZE];

        for( int x = 0; x < MAP_SIZE; x++ )
        {

            map->at(0)[i][x] = 0;

        }

    }

}
