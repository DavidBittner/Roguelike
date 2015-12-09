#include "class_controller.h"

#include <GLFW/glfw3.h>

std::vector<float> Controller::verts;
std::vector<float> Controller::colors;

Controller::Controller()
{



}

void Controller::Draw()
{

    this->verts.push_back( HitBox.pos.x );
    this->verts.push_back( HitBox.pos.y );

    this->verts.push_back( HitBox.pos.x+HitBox.bounds.x );
    this->verts.push_back( HitBox.pos.y );

    this->verts.push_back( HitBox.pos.x+HitBox.bounds.x );
    this->verts.push_back( HitBox.pos.y+HitBox.bounds.y );

    this->verts.push_back( HitBox.pos.x+HitBox.bounds.x );
    this->verts.push_back( HitBox.pos.y+HitBox.bounds.y );

    this->verts.push_back( HitBox.pos.x );
    this->verts.push_back( HitBox.pos.y+HitBox.bounds.y );

    this->verts.push_back( HitBox.pos.x );
    this->verts.push_back( HitBox.pos.y );

    glEnableClientState( GL_VERTEX_ARRAY );
    glVertexPointer( 2, GL_FLOAT, 0, verts.data() );
    glDrawArrays( GL_TRIANGLES, 0, verts.size()/2 );
    glDisableClientState( GL_VERTEX_ARRAY );

    verts.clear();

}
