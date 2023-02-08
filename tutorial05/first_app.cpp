
#include "first_app.hpp"


#include<stdexcept>
namespace VT{

    FirstApp::FirstApp(){
        createPipelineLayout();
        createPipeline();
        createCommandBuffers();
    }

    FirstApp::~FirstApp() {
        vkDestroyPipelineLayout(vtDevice.device(), pipelineLayout, nullptr);
    }

    void FirstApp::run(){
        while(!vtWindow.shouldClose()){
            glfwPollEvents();
        }
    }


    void FirstApp::createPipelineLayout(){
        VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
        pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutInfo.setLayoutCount = 0;
        pipelineLayoutInfo.pSetLayouts = nullptr;
        pipelineLayoutInfo.pushConstantRangeCount = 0;
        pipelineLayoutInfo.pPushConstantRanges = nullptr;

        if(vkCreatePipelineLayout(vtDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
            throw std::runtime_error("failed to create pipeline layout!");
        }
    }


    void FirstApp::createPipeline(){
        auto pipelineConfig = VTPipeline::defaultPipelineConfigInfo(vtSwapChain.width(), vtSwapChain.height());

        pipelineConfig.renderPass = vtSwapChain.getRenderPass();
        pipelineConfig.pipelineLayout = pipelineLayout;

        vtPipline = std::make_unique<VTPipeline>(vtDevice, "shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv", pipelineConfig);
    } 



    void FirstApp::createCommandBuffers(){}
    void FirstApp::drawFrame(){}
}