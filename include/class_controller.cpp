#include "class_controller.h"

std::vector<GLuint> Controller::objectBuffers;

Controller::Controller()
{

    objectBuffers.clear();

}

void Controller::Draw()
{

    for( GLuint i : objectBuffers )
    {

        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, i );
        //glDrawElements( GL_TRIANGLES, 3, GL

    }

}

void Controller::Terminate()
{

    for( GLuint i : objectBuffers )
    {

        glDeleteBuffers( 1, &i );

    }

    objectBuffers.clear();

}
