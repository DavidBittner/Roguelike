#include "class_controller.h"

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

    this->verts.push_back( HitBox.pos.x+HitBox.bounds.x );
    this->verts.push_back( HitBox.pos.y );

}
