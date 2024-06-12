#pragma once

#include <GL/glew.h>

class BufferManager {
    public:
     void setupBuffers(GLuint& VAO, GLuint& VBO);
     void cleanup(GLuint VAO, GLuint VBO);

    private:
};