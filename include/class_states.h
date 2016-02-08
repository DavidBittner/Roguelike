#pragma once

#include <GLFW/glfw3.h>

#include "class_controller.h"
#include "class_player.h"
#include "class_map.h"

#include "class_state.h"

/*
Init
---------------------------
*/
class Init : public State
{

    public:
        State *exec();

    private:
        Map *initMap;

};


/*
Poll
---------------------------
*/

class Poll : public State
{

    public:
        State *exec();

    private:
        Controller mainCont;

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
        Controller mainCont;

};


/*
Render
--------------------------
*/

class Render : public State
{

    public:
        State *exec();
        
    private:
        Controller mainCont;
        Map renderMap;

};

/*
Stop
--------------------------
*/

class Stop : public State
{

    State *exec();

};
