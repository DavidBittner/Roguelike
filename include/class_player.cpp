#include "class_player.h"
#include "struct_config.h"
#include "class_engine.h"

#include <iostream>

Player::Player()
{

    HitBox.bounds.x = GET_CONFIG().TILE_SIZE;
    HitBox.bounds.y = GET_CONFIG().TILE_SIZE;

    HitBox.pos.x = 0;
    HitBox.pos.y = 0;

    tarPos.x = 0;
    tarPos.y = 0;

}

void Player::Move()
{

    if( HitBox.pos.x < tarPos.x*GET_CONFIG().TILE_SIZE )
    {

        HitBox.pos.x++;

    }

}

void Player::KeyOps()
{

    bool *keys = ENGINE_GET().GetKeyStates();
    int tileSize = GET_CONFIG().TILE_SIZE;

    if( (tarPos.x == HitBox.pos.x/tileSize) && (tarPos.y == HitBox.pos.y/tileSize) )
    {

        if( keys[GLFW_KEY_D] )
        {

            tarPos.x++;
            std::printf( "Here\n" );

        }else if( keys[GLFW_KEY_A] )
        {

            tarPos.y--;

        }

    }

}
