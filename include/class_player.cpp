#include "class_player.h"

#include <cstdlib>
#include <iostream>
#include <vector>

Player::Player()
{

    getChildren().push_back( this );
    printf( "Player created. New size is %d. \n", int(getChildren().size()) );

    selfSprite.LoadTex( "test.png", 512, 256 );

    x = 0; y = 0;

}

void Player::Draw()
{
    
    static float f = 0.0f;
    f+=0.1f;

    selfSprite.Draw( 0, 0, 512, 256, f );

}

void Player::Move()
{



}
