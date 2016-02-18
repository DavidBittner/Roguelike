#include "class_mapgen.h"

MapGenerator::MapGenerator( int size )
{

    MAP_SIZE = size;

}

int MapGenerator::CheckNeighbors( int **map, int checkNum, int inx, int iny )
{

    int count = 0;

    for( int y = iny-1; y < iny+2; y++ )
    {

        for( int x = inx-1; x < inx+2; x++ )
        {

            if( x >= MAP_SIZE-1 || y >= MAP_SIZE-1 || x < 0 || y < 0 )
            {

                continue;

            }

            if( map[x][y] == checkNum )
            {

                count++;

            }

        }

    }

    return count;

}

bool MapGenerator::isIn( std::vector<Coord*> list, Coord check )
{

    for( unsigned i = 0; i < list.size(); i++ )
    {

        if( *list.at(i) == check )
        {

            return true;

        }

    }

    return false;

}

int **MapGenerator::GenMap()
{

    srand( time( nullptr ) );

    int **map = new int*[MAP_SIZE];

    for( int i = 0; i < MAP_SIZE; i++ )
    {

        map[i] = new int[MAP_SIZE];

        for( int j = 0; j < MAP_SIZE; j++ )
        {

            map[i][j] = 1;

        }

    }

    const int MINES = 10;
    for( int i = 0; i < MINES; i++ )
    {

        int randX = rand()%(MAP_SIZE-4);
        int randY = rand()%(MAP_SIZE-4);

        map[randX+2][randY+2] = 0;

    }

    std::vector<int*> test;
    test.push_back( new int(2) );

    const int CLICK_POINTS = 10;

    std::vector<Coord*> openList;
    std::vector<Coord*> closedList;

    for( int i = 0; i < CLICK_POINTS; i++ )
    {

        openList.clear();
        closedList.clear();

        Coord clickPos;
        clickPos.x = (rand()%(MAP_SIZE-4))+2;
        clickPos.y = (rand()%(MAP_SIZE-4))+2;

        openList.push_back( &clickPos ); 

        map[int(clickPos.x)][int(clickPos.y)] = 2; 
        
        while( openList.size() > 0 )
        {

            for( int y = openList.at(0)->y-1; y < openList.at(0)->y+2; y++ )
            {

                for( int x = openList.at(0)->x-1; x < openList.at(0)->x+2; x++ )
                {

                    if( ( x <= 2 || y <= 2 ) ||
                        ( x >= MAP_SIZE-2 || y >= MAP_SIZE-2 ) )
                    {
                        continue;
                    }
                    
                    if( !isIn( openList, Coord( x, y ) ) && !isIn( closedList, Coord( x, y ) ) )
                    {

                        if( CheckNeighbors( map, 0, x, y ) == 0 )
                        {

                            openList.push_back( new Coord( x, y ) );

                        }

                    }
                        
                }

            }

            closedList.push_back( openList.at(0) );
            if( openList.size() > 0 )
            {

                map[int(openList.at(0)->x)][int(openList.at(0)->y)] = 2;
                openList.erase( openList.begin() );

            }
           
       }

    }

    for( int y = 0; y < MAP_SIZE; y++ )
    {

        for( int x = 0; x < MAP_SIZE; x++ )
        {

            if( map[x][y] == 0 )
            {

                map[x][y] = 1;

            }

        }

    }

    openList.clear();
    closedList.clear();

    for( int i = 0; i < MAP_SIZE; i++ )
    {

        for( int j = 0; j < MAP_SIZE; j++ )
        {

            if( map[j][i] == 2 )
            {

                map[j][i] = 1;

            }else if( map[j][i] == 1 )
            {

                map[j][i] = 0;

            }
            printf( "%d", map[j][i] );

        }
        printf( "\n" );

    }

    return map;

}
