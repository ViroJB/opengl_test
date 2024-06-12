#pragma once

#include <iostream>
#include <GLFW/glfw3.h>

class GlfwManager {
    public:
    bool initialize();
    GLFWwindow* createWindow(int width, int height, const char* title);

    private:
    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);

};