#pragma once

#include <vector>

#include "class_sprite.h"
#include "struct_rect.h"

class Map
{

    public:
        Map( int size );
        Map();

        void AddNewLevel();
        void GenLevel();

        void LoadLevel( int level );
        void SaveMap( const char *filname );

        int  GetTile( int x, int y, int level );
        void SetTile( int x, int y, int level, int val );

        void Draw( Rect area, int level );

        bool IsPassable( int num );

    private:
        int mapsize = 0;
        static std::vector<int**> *map;

        static Sprite *mapSprite;

        void ForceInit();

};
