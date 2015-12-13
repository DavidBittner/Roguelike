#include "class_player.h"
#include "class_controller.h"
#include "struct_coord.h"

#include <GLFW/glfw3.h>

class ENGINE
{

    public:
        ENGINE();

        void Init( int WIND_WID, int WIND_HEI );
       
        void Poll();
        void Process();
        void Render();

        void Stop();

        void Reshape( GLFWwindow *wind, int width, int height );
        void KeyFunc( GLFWwindow *wind, int key, int scancode, int action, int mods );
        
        void SetCamera( Coord *camera );

        bool *GetKeyStates();

    private:
        const float FRAMES_PER_SECOND = 60.0f;
        float etime, stime;

        GLFWwindow *wind;

        int WIND_WID, WIND_HEI;

        Controller *Ply;

        Coord camera;
        bool *keyStates;

};

ENGINE &ENGINE_GET();
void glfwReshape( GLFWwindow *wind, int width, int height );
void glfwKeyFunc();
