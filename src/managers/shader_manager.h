#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <fstream>
#include <sstream>

#include <fmt/core.h>
#include "../render/renderable_object.h"


class ShaderManager {
   public:
    ShaderManager();
    //  GLuint compileAndLinkShaders(const char* vertexShaderSource, const char* fragmentShaderSource);
    GLuint compileAndLinkShaders();
    void loadShaderSourcesFromFile(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    void setOffset(const RenderableObject& obj);
    void transform(const RenderableObject& obj);

   private:
    std::string m_vertexShaderSource;
    std::string m_fragmentShaderSource;
    GLuint m_shaderProgram;
};