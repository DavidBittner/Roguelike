#pragma once

#include <vector>

class Map
{

    public:
        Map( int size );

        void GenLevel( int level );
        void LoadLevel( int level );
        void SaveMap( const char *filname );

        int GetTile( int x, int y, int level );
        int SetTile( int x, int y, int level );

    private:
        int MAP_SIZE = 50;
        static std::vector<int**> *map;

        void ForceInit();
        
};
