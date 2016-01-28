#pragma once

#include <GLFW/glfw3.h>

#include "class_state.h"

/*
Init
---------------------------
*/
class Init : public State
{

    State *exec();

};


/*
Poll
---------------------------
*/

class Poll : public State
{

    State *exec();

};

/*
Process
--------------------------
*/

class Process : public State
{

    State *exec();

};


/*
Render
--------------------------
*/

class Render : public State
{

    State *exec();

};

/*
Stop
--------------------------
*/

class Stop : public State
{

    State *exec();

};
