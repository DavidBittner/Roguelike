#include "class_player.h"

#include <cstdlib>
#include <iostream>
#include <vector>

Player::Player()
{

    getChildren().push_back( this );
    printf( "Player created. New size is %d. \n", int(getChildren().size()) );

    selfSprite.LoadTex( "test.png", 512, 512 );

}

void Player::Draw()
{

    selfSprite.Draw( x, y, 32, 32, 0.0f );

}

void Player::Move()
{



}
