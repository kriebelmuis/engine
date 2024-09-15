#include <iostream>

#include "engine/instance.h"

int main() {
    ohEngine::ohInstance app{};

    try {
        app.init();
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}
