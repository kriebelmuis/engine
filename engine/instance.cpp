#include "instance.h"

namespace nivalis {
    void nvInstance::init() {
        while(!instance.shouldClose())
            glfwPollEvents();
    }
}