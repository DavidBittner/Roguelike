#include "class_state.h"
#include "class_states.h"

class Engine
{

    public:
        Engine();

    private:
        State *curState;

        static Init    stateInit;
        static Poll    statePoll;
        static Process stateProc;
        static Render  stateRend;
        static Stop    stateStop;

};
