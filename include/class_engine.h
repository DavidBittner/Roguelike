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

        void start();
        void end();
        void cap();

    private:
        State *curState;

        static Init    stateInit;
        static Poll    statePoll;
        static Process stateProc;
        static Render  stateRend;
        static Stop    stateStop;

        static GLFWwindow *window;

        bool termed;

        const float FRAMES_PER_SECOND = 60.0f;
        float stime = 0.0f, etime = 0.0f;

};

Engine &GetEngine();
