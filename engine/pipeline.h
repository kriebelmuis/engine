#pragma once

#include "device.h"

#include <string>
#include <vector>

namespace nivalis {
    struct nvPipelineConfig {
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

    class nvPipeline {
    public:
        nvPipeline(nvDevice& device, const std::string& vertPath, const std::string& fragPath, const nvPipelineConfig& config);
        ~nvPipeline();

        nvPipeline(const nvPipeline&) = delete;
        void operator=(const nvPipeline&) = delete;

        static nvPipelineConfig defaultPipelineConfig(uint32_t width, uint32_t height);

    private:
        static std::vector<char> readFile(const std::string& path);

        void createPipeline(const std::string& vertPath, const std::string& fragPath, const nvPipelineConfig& config);
        void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

        nvDevice& device;
        VkPipeline pipeline;
        VkShaderModule nvFragModule;
        VkShaderModule nvVertModule;
    };
}