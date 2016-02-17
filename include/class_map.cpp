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

    map->push_back( new int*[mapsize] );

    for( int y = 0; y < mapsize; y++ )
    {

        map->at( map->size()-1 )[y] = new int[mapsize];
        for( int x = 0; x < mapsize; x++ )
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

    mapsize = size;

    ForceInit();

    AddNewLevel();

    mapSprite = new Sprite();
    mapSprite->LoadTex( "art/game/floor.png", 128, 128, 2, 2 );

}

int Map::GetTile( int x, int y, int level )
{

    return map->at(level)[x][y];

}

void Map::SetTile( int x, int y, int level, int val )
{

    map->at(level)[x][y] = val;

}

void Map::Draw( Rect area, int level )
{

    int xMax = area.pos.x+area.bnd.x;
    int yMax = area.pos.y+area.bnd.y;

    float tileSize = GetEngine().GetAsp( TILE_SIZE ); 

    glEnable( GL_TEXTURE_2D );
    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_TEXTURE_COORD_ARRAY );

    for( int y = area.pos.y; y < yMax; y++ )
    {

        for( int x = area.pos.x; x < xMax; x++ )
        {
            
            srand( x*y );
            int orient = rand()%4;
            mapSprite->Draw( map->at(level)[x][y], x*tileSize, y*tileSize, tileSize, tileSize, orient*90 ); 

        }

    }

    glDisableClientState( GL_TEXTURE_COORD_ARRAY );
    glDisableClientState( GL_VERTEX_ARRAY );
    glDisable( GL_TEXTURE_2D );

}

bool Map::IsPassable( int num )
{

    int passable[] = { 0, -1 };

    for( int i = 0; passable[i] != -1; i++ )
    {

        if( passable[i] == num )
        {

            return true;

        }

    }

    return false;

}
