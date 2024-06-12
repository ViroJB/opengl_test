#pragma once

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

#include <fmt/core.h>
#include "renderable_object.h"
#include "../managers/shader_manager.h"


class Renderer {
    public:
        Renderer();
        void render(GLFWwindow* window, std::vector<RenderableObject>& renderObjects, GLuint VAO, GLuint VBO);
        void setShaderProgram(GLuint shaderProgram);
        GLuint getShaderProgram();
    private:
        ShaderManager m_shaderManager = ShaderManager();
        GLuint m_shaderProgram;
};