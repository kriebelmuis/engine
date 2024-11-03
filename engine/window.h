#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace nivalis {
    class nvWindow {
    public:
        nvWindow(int w, int h, std::string name);
        ~nvWindow();

        nvWindow(const nvWindow &) = delete;
        nvWindow &operator=(const nvWindow &) = delete;

        bool shouldClose() {
            return glfwWindowShouldClose(window);
        }

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

    private:
        void init();

        const int width;
        const int height;

        std::string windowName;
        GLFWwindow *window;
    };
}