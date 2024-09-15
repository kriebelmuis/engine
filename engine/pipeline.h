#pragma once

#include "device.h"

#include <string>
#include <vector>

namespace ohEngine {
    struct ohPipelineConfig {
        VkViewport viewport;
        VkRect2D scissor;
        VkPipelineViewportStateCreateInfo viewportInfo;
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

    class ohPipeline {
    public:
        ohPipeline(ohDevice& device, const std::string& vertPath, const std::string& fragPath, const ohPipelineConfig& config);
        ~ohPipeline();

        ohPipeline(const ohPipeline&) = delete;
        void operator=(const ohPipeline&) = delete;

        static ohPipelineConfig defaultPipelineConfig(uint32_t width, uint32_t height);

    private:
        static std::vector<char> readFile(const std::string& path);

        void createPipeline(const std::string& vertPath, const std::string& fragPath, const ohPipelineConfig& config);
        void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

        ohDevice& device;
        VkPipeline pipeline;
        VkShaderModule ohFragModule;
        VkShaderModule ohVertModule;
    };
}