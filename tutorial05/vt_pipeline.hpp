#pragma once

#include "vt_device.hpp"
#include<string>
#include<vector>

namespace VT {

    struct PipelineConfigInfo {
        VkViewport viewport;
        VkRect2D scissor;
        VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
        VkPipelineRasterizationStateCreateInfo rasterizationInfo;
        VkPipelineMultisampleStateCreateInfo multisampleInfo;
        VkPipelineColorBlendAttachmentState colorBlendAttachment;
        VkPipelineColorBlendStateCreateInfo colorBlendInfo;
        VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
        VkPipelineLayout pipelineLayout = nullptr;
        VkRenderPass renderPass = nullptr;
        uint32_t subpass = 0;
    };
    class VTPipeline
    {
        public:
            VTPipeline(VTDevice& device, const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo);
            ~VTPipeline();
            VTPipeline(const VTPipeline &) = delete;
            void operator=(const VTPipeline &) = delete;

            static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint16_t height);
        
        private:
            static std::vector<char> readFile(const std::string &filpath);
            void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo);
            void createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule);
            VTDevice& vtDevice;
            VkPipeline graphicsPipeline;
            VkShaderModule vertShaderModule;
            VkShaderModule fragShaderModule;
    };
}