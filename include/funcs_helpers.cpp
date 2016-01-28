#include "funcs_helpers.h"

void KeyHelper( GLFWwindow *window, int key, int scancode, int action, int mods )
{

    GetKeyboard().KeyCallback( window, key, scancode, action, mods );

}

void ReshapeHelper( GLFWwindow *window, int width, int height )
{

    glfwMakeContextCurrent( window );

    glViewport( 0, 0, (GLsizei)width, (GLsizei)height );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( -width/2.0, width/2.0, -height/2.0, height/2.0, 1.0f, 5.0f ); 
    glMatrixMode( GL_MODELVIEW );

}

