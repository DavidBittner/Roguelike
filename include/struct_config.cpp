#include "struct_config.h"

ENG_CONFIG& GET_CONFIG()
{

    static ENG_CONFIG *createNew = new ENG_CONFIG( 64, Coord( 50, 50 ) );
    return *createNew;

}

ENG_CONFIG::ENG_CONFIG( int TILE_SIZE, Coord MAP_SIZE ) : TILE_SIZE( TILE_SIZE ), 
                                                          MAP_SIZE( MAP_SIZE )
{



}
