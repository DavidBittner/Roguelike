#include "class_player.h"

#include <cstdlib>
#include <iostream>
#include <vector>

Player::Player()
{

    getChildren().push_back( this );
    printf( "Player created. New size is %d. \n", int(getChildren().size()) );

    selfSprite.LoadTex( "test.png", 512, 512 );

    x = 0; y = 0;

}

void Player::Draw()
{

    selfSprite.Draw( 0, 0, 320, 320, 45.0f );

}

void Player::Move()
{



}
