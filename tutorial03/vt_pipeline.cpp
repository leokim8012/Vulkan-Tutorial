#include "vt_pipeline.hpp"

#include<fstream>
#include <stdexcept>
#include<iostream>


namespace VT {

    VTPipeline::VTPipeline(VTDevice &device, const std::string &vertFilepath, const std::string &fragFilepath, const PipelineConfigInfo& configInfo) : vtDevice{device} {
        createGraphicsPipeline(vertFilepath, fragFilepath, configInfo);
    }
    std::vector<char> VTPipeline::readFile(const std::string& filepath) {
        std::ifstream file{filepath, std::ios::ate | std::ios::binary};

        if(!file.is_open()){
            throw std::runtime_error("failed to open file: " + filepath);
        }

        size_t fileSize = static_cast<size_t>(file.tellg());

        std::vector<char> buffer(fileSize);
        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();

        return buffer;
    } 
    void VTPipeline::createGraphicsPipeline(const std::string &vertFilepath, const std::string &fragFilepath, const PipelineConfigInfo& configInfo) {
        auto vertCode = readFile(vertFilepath);
        auto fragCode = readFile(fragFilepath);

        std::cout << "Vertex Sharder Code Size: " << vertCode.size() << "\n";
        std::cout << "Fragment Sharder Code Size: " << fragCode.size() << "\n";
    }

    void VTPipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule) {
        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t *>(code.data());


        if(vkCreateShaderModule(vtDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
            throw std::runtime_error("failed to create shader module");
        }
    }


    PipelineConfigInfo VTPipeline::defaultPipelineConfigInfo(uint32_t width, uint16_t height) {
        PipelineConfigInfo configInfo{};

        return configInfo;
    }
}