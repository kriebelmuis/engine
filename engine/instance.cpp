#include "instance.h"

namespace ohEngine {
    void ohInstance::init() {
        while(!instance.shouldClose())
            glfwPollEvents();
    }
}