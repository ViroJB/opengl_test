#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fmt/core.h>
#include <thread>

#include <vector>

#include "../managers/buffer_manager.h"
#include "../managers/glew_manager.h"
#include "../managers/glfw_manager.h"
#include "../managers/shader_manager.h"
#include "../render/renderer.h"
#include "../input/input.h"

struct GameState {

};

class Game {
   public:
    Game();
    void run();
    void cleanup();

   private:
    GameState m_gameState;
    Input* m_input;
    std::vector<RenderableObject> m_renderObjects;
    GLFWwindow* m_window;
    GlfwManager m_glfwManager;
    GlewManager m_glewManager;
    BufferManager m_bufferManager;
    Renderer* m_renderer;

    GLuint m_VAO, m_VBO;
};