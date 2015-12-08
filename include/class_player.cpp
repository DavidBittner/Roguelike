#include "class_player.h"

#include <iostream>

Player::Player()
{

    HitBox.bounds.x = 32;
    HitBox.bounds.y = 32;

}

void Player::Move()
{

    std::cout << "moved" << std::endl;

}

void Player::KeyOps()
{



}
