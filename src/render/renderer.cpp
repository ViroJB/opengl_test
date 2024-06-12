#include "renderer.h"

Renderer::Renderer() {
    // m_shaderManager = ShaderManager();
    m_shaderProgram = m_shaderManager.compileAndLinkShaders();
    glUseProgram(m_shaderProgram);
}

void Renderer::setShaderProgram(GLuint shaderProgram) {
    m_shaderProgram = shaderProgram;
}

GLuint Renderer::getShaderProgram() {
    return m_shaderProgram;
}

void Renderer::render(GLFWwindow* window, std::vector<RenderableObject>& renderObjects, GLuint VAO, GLuint VBO) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    for (const auto& obj : renderObjects) {
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // wireframe mode

        GLfloat combinedData[21];  // 3 vertices * (3 position + 4 color) = 21 elements
        for (int i = 0; i < 3; ++i) {
            combinedData[i * 7 + 0] = obj.vertices[i * 3 + 0];  // x
            combinedData[i * 7 + 1] = obj.vertices[i * 3 + 1];  // y
            combinedData[i * 7 + 2] = obj.vertices[i * 3 + 2];  // z
            combinedData[i * 7 + 3] = obj.colors[i * 4 + 0];    // r
            combinedData[i * 7 + 4] = obj.colors[i * 4 + 1];    // g
            combinedData[i * 7 + 5] = obj.colors[i * 4 + 2];    // b
            combinedData[i * 7 + 6] = obj.colors[i * 4 + 3];    // a
        }

        glBufferData(GL_ARRAY_BUFFER, sizeof(combinedData), combinedData, GL_STATIC_DRAW);

        // GLint offsetLoc = glGetUniformLocation(m_shaderProgram, "offset");
        // glUniform2fv(offsetLoc, 1, obj.position);
        // m_shaderManager.setOffset(obj);
        m_shaderManager.transform(obj);

        GLsizei stride = 7 * sizeof(GLfloat);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (GLvoid*)0);

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, stride, (GLvoid*)(3 * sizeof(GLfloat)));
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}