#include "class_player.h"

#include <cstdlib>
#include <iostream>
#include <vector>

Player::Player()
{

    childControls.push_back( this );
    printf( "Player created. New size is %d", int(childControls.size()) );

}

void Player::Draw()
{

    selfSprite.Draw( x, y, 32, 32, 0.0f );

}

void Player::Move()
{



}
