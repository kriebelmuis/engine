#pragma once

#include "window.h"
#include "pipeline.h"
#include "device.h"

namespace nivalis {
    class nvInstance {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void init();
    private:
        nvWindow instance{WIDTH, HEIGHT, "nivalis"};
        nvDevice device{instance};
        nvPipeline pipeline{device, "shaders/shader.vert.spv", "shaders/shader.frag.spv", nvPipeline::defaultPipelineConfig(WIDTH, HEIGHT)};
    };
}