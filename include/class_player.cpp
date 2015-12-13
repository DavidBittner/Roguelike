#include "class_player.h"
#include "struct_config.h"
#include "class_engine.h"

#include <iostream>

Player::Player()
{

    HitBox.bounds.x = GET_CONFIG().TILE_SIZE;
    HitBox.bounds.y = GET_CONFIG().TILE_SIZE;

    HitBox.pos.x = 100;
    HitBox.pos.y = 100;

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

    if( keys[GLFW_KEY_A] )
    {

        tarPos.x+=1;
        std::printf( "here %d\n", (int)tarPos.x );

    }

}
