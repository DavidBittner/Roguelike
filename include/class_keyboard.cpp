#include <GLFW/glfw3.h>

#include <iostream>
#include <cstdlib>

#include "class_keyboard.h"

Keyboard &GetKeyboard()
{

    static Keyboard *keys = new Keyboard();
    return *keys;

}

Keyboard::Keyboard()
{

    keyStates = new bool[256];
    keyPressedStates = new bool[256];

}

void Keyboard::KeyCallback( GLFWwindow *window, int key, int scancode, int action, int mods )
{

    if( action == GLFW_PRESS )
    {
        
        keyStates[key] = true;
        keyPressedStates[key] = true;

    }else if( action == GLFW_RELEASE )
    {

        keyStates[key] = false;

    }

}

void Keyboard::ResetKeys()
{

    for( int i = 0; i < 256; i++ )
    {

        keyPressedStates[i] = false;

    }

}

bool Keyboard::GetKey( int key )
{

    return keyStates[key];

}

bool Keyboard::GetKeyPressed(int key )
{

    return keyPressedStates[key];

}
