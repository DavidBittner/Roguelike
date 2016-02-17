#include "class_player.h"
#include "class_keyboard.h"
#include "class_engine.h"

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

Player::Player()
{

    getChildren().push_back( this );
    printf( "Player created. New size is %d. \n", int(getChildren().size()) );

    selfSprite.LoadTex( "art/game/ply.png", 128, 128, 1, 1 );

    pos.x = 0.0f;
    pos.y = 0.0f;

    hitBox.bnd.x = GetEngine().GetAsp( TILE_SIZE );
    hitBox.bnd.y = hitBox.bnd.x;

    targPos.x = 0.0f;
    targPos.y = 0.0f;

    Render tempInstance;
    tempInstance.SetPerspective( &pos );

}

void Player::Draw()
{
    
    selfSprite.Draw( pos.x, pos.y, hitBox.bnd.x, hitBox.bnd.y, 0.0f );

}

void Player::KeyOps()
{

    double tileSize = GetEngine().GetAsp( TILE_SIZE );
    Coord simPos = Coord( pos.x/tileSize, pos.y/tileSize );

    if( simPos == targPos )
    {
    
        if( GetKeyboard().GetKey( GLFW_KEY_A ) )
        {

            if( targPos.x > 0 )
            {

                if( mapInstance.IsPassable( mapInstance.GetTile(targPos.x-1, targPos.y, level) ) )
                {

                    targPos.x--;

                }

            }

        }else if( GetKeyboard().GetKey( GLFW_KEY_D ) )
        {

            if( targPos.x < GetEngine().GetAsp( MAP_SIZE )-1 )
            {

                if( mapInstance.IsPassable( mapInstance.GetTile(targPos.x+1, targPos.y, level) ) )
                {

                    targPos.x++;

                }

            }

        }else if( GetKeyboard().GetKey( GLFW_KEY_W ) )
        {

            if( targPos.y < GetEngine().GetAsp( MAP_SIZE )-1 )
            {

                if( mapInstance.IsPassable( mapInstance.GetTile(targPos.x, targPos.y+1, level) ) )
                {

                    targPos.y++;

                }

            }

        }else if( GetKeyboard().GetKey( GLFW_KEY_S ) )
        {

            if( targPos.y > 0 )
            {

                if( mapInstance.IsPassable( mapInstance.GetTile(targPos.x, targPos.y-1, level) ) )
                {

                    targPos.y--;

                }

            }

        }

    }

}

void Player::Move()
{

    double tileSize = GetEngine().GetAsp( TILE_SIZE );
    Coord simPos = Coord( pos.x/tileSize, pos.y/tileSize );

    if( simPos.x < targPos.x )
    {

        if( ((pos.x + movSpeed)/tileSize) > targPos.x )
        {

            pos.x = targPos.x*tileSize;

        }else
        {

            pos.x+=movSpeed;

        }

    }else if( simPos.x > targPos.x )
    {

        if( ((pos.x - movSpeed)/tileSize) < targPos.x )
        {

            pos.x = targPos.x*tileSize;

        }else
        {

            pos.x-=movSpeed;

        }

    }else if( simPos.y < targPos.y )
    {

        if( ((pos.y+movSpeed)/tileSize) > targPos.y )
        {

            pos.y = targPos.y*tileSize;

        }else
        {

            pos.y+=movSpeed;

        }

    }else if( simPos.y > targPos.y )
    {

        if( ((pos.y-movSpeed)/tileSize) < targPos.y )
        {

            pos.y = targPos.y*tileSize;

        }else
        {

            pos.y-=movSpeed;

        }

    }

    hitBox.pos.x = pos.x;
    hitBox.pos.y = pos.y;

}
