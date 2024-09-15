#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace ohEngine {
    class ohWindow {
    public:
        ohWindow(int w, int h, std::string name);
        ~ohWindow();

        ohWindow(const ohWindow &) = delete;
        ohWindow &operator=(const ohWindow &) = delete;

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