#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include<string>
namespace VT {
    class VTWindow
    {
        public:
            VTWindow(int w, int h, std::string name);
            ~VTWindow();
            bool shouldClose() { return glfwWindowShouldClose(window); }
            VkExtent2D getExtent() {
                return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)};
            };
            void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

            VTWindow(const VTWindow &) = delete;
            VTWindow &operator=(const VTWindow &) = delete;
        private:
            void initWindow();
            const int width;
            const int height;

            std::string windowName;
            GLFWwindow *window;
    };
}