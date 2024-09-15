#include "window.h"

#include <stdexcept>

namespace ohEngine {
    ohWindow::ohWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name} {
        init();
    }

    ohWindow::~ohWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void ohWindow::init() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }

    void ohWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
            throw std::runtime_error("failed to create window surface");
        }
    };
}