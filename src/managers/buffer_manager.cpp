#include "buffer_manager.h"

void BufferManager::setupBuffers(GLuint& VAO, GLuint& VBO) {
    // Define the vertex data for a triangle
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    // Create a vertex buffer object (VBO)
    glGenBuffers(1, &VBO);

    // Create a vertex array object (VAO)
    glGenVertexArrays(1, &VAO);

    // Bind the VAO
    glBindVertexArray(VAO);

    // Bind the VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Define the vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // Unbind the VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void BufferManager::cleanup(GLuint VAO, GLuint VBO) {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}