
#include "first_app.hpp"

namespace VT{

    void FirstApp::run(){
        while(!VTWindow.shouldClose()){
            glfwPollEvents();
        }
    }
}