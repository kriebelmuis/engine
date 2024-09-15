#pragma once

#include "window.h"
#include "pipeline.h"
#include "device.h"

namespace ohEngine {
    class ohInstance {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void init();
    private:
        ohWindow instance{WIDTH, HEIGHT, "ohEngine"};
        ohDevice device{instance};
        ohPipeline pipeline{device, "shaders/shader.vert.spv", "shaders/shader.frag.spv", ohPipeline::defaultPipelineConfig(WIDTH, HEIGHT)};
    };
}