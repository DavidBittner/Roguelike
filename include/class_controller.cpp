#include "class_controller.h"

#include <iostream>
#include <cstdlib>

std::vector<Controller*> Controller::childControls;

Controller::Controller()
{

    childControls.clear();

}

void Controller::Draw()
{

    glPushMatrix();

        glEnable( GL_TEXTURE_2D );

        glEnableClientState( GL_VERTEX_ARRAY );
        glEnableClientState( GL_TEXTURE_COORD_ARRAY );

        for( unsigned i = 0; i < childControls.size(); i++ )
        {

            childControls.at(i)->Draw();

        }

        glDisable( GL_TEXTURE_2D );

        glDisableClientState( GL_VERTEX_ARRAY );
        glDisableClientState( GL_TEXTURE_COORD_ARRAY );

    glPopMatrix();

}

void Controller::Move()
{

    printf( "Fucking idiot, what the fuck are you fucking trying?\n" );

}

void Controller::Terminate()
{

    for( unsigned i = 0; i < childControls.size(); i++ )
    {

        childControls.at(i)->Terminate();

    }

    childControls.clear();

}
