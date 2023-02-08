#pragma once

#include "vt_window.hpp"
#include "vt_pipeline.hpp"
#include "vt_device.hpp"
#include "vt_swap_chain.hpp"
#include <memory>
#include <vector>


namespace VT{
    class FirstApp {

        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT =600;

            FirstApp();
            ~FirstApp();

            FirstApp(const FirstApp &) = delete;
            FirstApp &operator=(const FirstApp &) = delete;
            void run();


        private:
            void createPipelineLayout();
            void createPipeline();
            void createCommandBuffers();
            void drawFrame();


            VTWindow vtWindow{
                WIDTH, HEIGHT, "New window"};

            VTDevice vtDevice{
                vtWindow};

            VTSwapChain vtSwapChain{
                vtDevice,
                vtWindow.getExtent()};

            std::unique_ptr<VTPipeline> vtPipeline;


            VkPipelineLayout pipelineLayout;
            std::vector<VkCommandBuffer> commandBuffers;


            // VTPipeline vtPipeline{
            //     vtDevice,
            //     "shaders/simple_shader.vert.spv",
            //     "shaders/simple_shader.frag.spv",
            //     VTPipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
            // };
    };
}