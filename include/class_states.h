#include "class_state.h"

/*
Init
---------------------------
*/
class Init : public State
{

    void exec();

};


/*
Poll
---------------------------
*/

class Poll : public State
{

    void exec();

};

/*
Process
--------------------------
*/

class Process : public State
{

    void exec();

};


/*
Render
--------------------------
*/

class Render : public State
{

    void exec();

};

/*
Stop
--------------------------
*/

class Stop : public State
{

    void exec();

};
