#include <GLFW/glfw3.h>
#include <iostream>

#include "include/class_player.h"
#include "include/class_controller.h"

#include "include/struct_config.h"

void Reshape( GLFWwindow *wind, int width, int height )
{

    glfwMakeContextCurrent( wind );

    glViewport( 0, 0, (GLsizei)width, (GLsizei)height );
    glMatrixMode( GL_PROJECTION );

    glLoadIdentity();
    glOrtho( -width/2.0f, width/2.0f, -height/2.0f, height/2.0f, 1.0f, 2.0f );

    glMatrixMode( GL_MODELVIEW );

}

void GAME_CONFIG()
{

    std::cout << GET_CONFIG().TILE_SIZE << std::endl;

}

int main()
{

    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    if( glfwInit() != GL_TRUE )
    {
        std::printf( "Failed to initalize GLFW. Closing.\n" );
        glfwTerminate();
    }

    GLFWwindow *wind = glfwCreateWindow( WINDOW_WIDTH, WINDOW_HEIGHT, "Roguelike", nullptr, nullptr );
    glfwMakeContextCurrent( wind );

    Reshape( wind, WINDOW_WIDTH, WINDOW_HEIGHT );
    glfwSetWindowSizeCallback( wind, Reshape );

    Controller *player = new Player();

    GAME_CONFIG();

    while( !glfwWindowShouldClose( wind ) )
    {

        glClear( GL_COLOR_BUFFER_BIT );
        glLoadIdentity();
        glTranslatef( 0.0f, 0.0f, -1.0f );

        player->Move();
        player->Draw();

        glfwPollEvents();
        glfwSwapBuffers( wind );
    
    }
    
    glfwTerminate();

}
