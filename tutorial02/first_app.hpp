#pragma once

#include "vt_window.hpp"
#include "vt_pipline.hpp"
namespace VT{
    class FirstApp {

        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT =600;

            void run();

        private:
            VTWindow vTWindow{
                WIDTH, HEIGHT, "New window"
            };

            VTPipline vTPipline{
                "shaders/simple_shader.vert.spv",
                "shaders/simple_shader.frag.spv",
            };
    };
}