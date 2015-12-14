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

    float movSpeed = (GET_CONFIG().TILE_SIZE/32)*2;

    if( HitBox.pos.x < tarPos.x*GET_CONFIG().TILE_SIZE )
    {

        HitBox.pos.x+=movSpeed;

    }else if( HitBox.pos.x > tarPos.x*GET_CONFIG().TILE_SIZE )
    {

        HitBox.pos.x-=movSpeed;

    }else if( HitBox.pos.y < tarPos.y*GET_CONFIG().TILE_SIZE )
    {

        HitBox.pos.y+=movSpeed;

    }else if( HitBox.pos.y > tarPos.y*GET_CONFIG().TILE_SIZE )
    {

        HitBox.pos.y-=movSpeed;

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

        }else if( keys[GLFW_KEY_A] )
        {

            tarPos.x--;

        }else if( keys[GLFW_KEY_S] )
        {

            tarPos.y--;

        }else if( keys[GLFW_KEY_W] )
        {

            tarPos.y++;

        }

    }

}
