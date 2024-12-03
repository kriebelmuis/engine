cmake_minimum_required(VERSION 3.25)
project(nivalis)

# prepare dependencies
include(FetchContent)
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG latest
)
FetchContent_MakeAvailable(glfw)

find_package(Vulkan REQUIRED)

if (Vulkan_FOUND)
    include_directories(${Vulkan_INCLUDE_DIRS})
    link_directories(${Vulkan_LIBRARY_DIRS})
else()
    message(FATAL_ERROR "Could not find Vulkan library!")
endif()

set(CMAKE_CXX_STANDARD 17)

# add files
add_executable(nivalis
        engine/window.h
        engine/window.cpp
        engine/instance.h
        engine/instance.cpp
        engine/pipeline.h
        engine/pipeline.cpp
        engine/device.h
        engine/device.cpp

        main.cpp
        engine/swapchain.cpp
        engine/swapchain.h
)

# copy shaders
file(COPY shaders DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

# link libraries
target_link_libraries(nivalis glfw ${Vulkan_LIBRARIES})