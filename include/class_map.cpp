#include "class_map.h"
#include "class_engine.h"

#include <iostream>
#include <vector>

std::vector<int**> *Map::map;
Sprite *Map::mapSprite;

void Map::ForceInit()
{

    map = new std::vector<int**>;

}

void Map::AddNewLevel()
{

    map->push_back( new int*[MAP_SIZE] );

    for( int y = 0; y < MAP_SIZE; y++ )
    {

        map->at( map->size()-1 )[y] = new int[MAP_SIZE];
        for( int x = 0; x < MAP_SIZE; x++ )
        {

           map->at( map->size()-1 )[y][x] = 0; 

        }

    }

}

Map::Map()
{

    

}

Map::Map( int size )
{

    printf( "Map initialized with size %d.\n", size );

    MAP_SIZE = size;

    ForceInit();
    map->push_back( new int*[MAP_SIZE] );

    AddNewLevel();

    mapSprite = new Sprite();
    mapSprite->LoadTex( "tem.png", 32, 32 );

}

int Map::GetTile( int x, int y, int level )
{

    return map->at(level)[x][y];

}

void Map::SetTile( int x, int y, int level, int val )
{

    map->at(level)[x][y] = val;

}

void Map::Draw( Rect area )
{

    int xMax = area.pos.x+area.bnd.x;
    int yMax = area.pos.y+area.bnd.y;

    float tileSize = GetEngine().GetAsp( TILE_SIZE ); 

    glEnable( GL_TEXTURE_2D );
    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_TEXTURE_COORD_ARRAY );

    for( int y = 0; y < yMax; y++ )
    {

        for( int x = 0; x < xMax; x++ )
        {
            
            mapSprite->Draw( x*tileSize, y*tileSize, tileSize, tileSize, 0.0f ); 

        }

    }

    glDisableClientState( GL_TEXTURE_COORD_ARRAY );
    glDisableClientState( GL_VERTEX_ARRAY );
    glDisable( GL_TEXTURE_2D );

}
