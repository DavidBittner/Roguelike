#pragma once

#include <GLFW/glfw3.h>

class Keyboard
{

    public:
        Keyboard();

        void KeyCallback( GLFWwindow *window, int key, int scancode, int action, int mods );

        void ResetKeys();

        bool GetKey( int key );
        bool GetKeyPressed( int key );

    private:
        bool *keyStates;
        bool *keyPressedStates;

};

Keyboard &GetKeyboard();
