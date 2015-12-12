#include "class_player.h"
#include "class_controller.h"

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
        void KeyFunc();
        
    private:
        GLFWwindow *wind;

        int WIND_WID, WIND_HEI;

        Controller *Ply;

};

ENGINE &ENGINE_GET();
void glfwReshape( GLFWwindow *wind, int width, int height );
void KeyFunc();
