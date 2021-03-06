#include "class_controller.h"

#include <iostream>
#include <cstdlib>

Controller::Controller()
{


}

std::vector<Controller*> &Controller::getChildren()
{

    static std::vector<Controller*> *childs = new std::vector<Controller*>;
    return *childs;

}

void Controller::Draw()
{

    glPushMatrix();

        glEnable( GL_TEXTURE_2D );

        glEnableClientState( GL_VERTEX_ARRAY );
        glEnableClientState( GL_TEXTURE_COORD_ARRAY );

        for( Controller *i : getChildren() )
        {

            i->Draw();

        }

        glDisable( GL_TEXTURE_2D );

        glDisableClientState( GL_VERTEX_ARRAY );
        glDisableClientState( GL_TEXTURE_COORD_ARRAY );

    glPopMatrix();

}

void Controller::Move()
{

    for( Controller *i : getChildren() )
    {

        i->Move();

    }

}

void Controller::KeyOps()
{

    for( Controller *i : getChildren() )
    {

        i->KeyOps();

    }

}

void Controller::Terminate()
{

    for( unsigned i = 0; i < getChildren().size(); i++ )
    {

        getChildren().at(i)->Terminate();

    }

    getChildren().clear();

}
