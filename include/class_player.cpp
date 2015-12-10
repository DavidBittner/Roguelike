#include "class_player.h"
#include "struct_config.h"

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


}

void Player::KeyOps()
{



}
