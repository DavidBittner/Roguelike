#pragma once

#include <GLFW/glfw3.h>

#include "class_controller.h"
#include "class_player.h"
#include "class_state.h"

/*
Init
---------------------------
*/
class Init : public State
{

    public:
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

    public:
        State *exec();

        void InitializePlayer();

    private:
        Player *ply;

};


/*
Render
--------------------------
*/

class Render : public State
{

    Controller mainCont;
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
