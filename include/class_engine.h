#pragma once

#include <iostream>
#include <GLFW/glfw3.h>

#include "class_state.h"
#include "class_states.h"

#include "class_controller.h"
#include "class_player.h"

class Engine
{

    friend class Init;
    friend class Poll;
    friend class Process;
    friend class Render;
    friend class Stop;

    public:
        Engine();

        void Fire();

        bool GetTerm();

    private:
        State *curState;

        static Init    stateInit;
        static Poll    statePoll;
        static Process stateProc;
        static Render  stateRend;
        static Stop    stateStop;

        static GLFWwindow *window;

        Controller mainCont;
        Player ply;

        bool termed;

};

Engine &GetEngine();
