#pragma once

#include "vt_window.hpp"
#include "vt_pipeline.hpp"
#include"vt_device.hpp"


namespace VT{
    class FirstApp {

        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT =600;

            void run();

        private:
            VTWindow vtWindow{
                WIDTH, HEIGHT, "New window"
            };

            VTDevice vtDevice{
                vtWindow};

            VTPipeline vtPipeline{
                vtDevice,
                "shaders/simple_shader.vert.spv",
                "shaders/simple_shader.frag.spv",
                VTPipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
            };
    };
}