#pragma once

#include <GL/glew.h>

struct RenderableObject {
    GLfloat vertices[9];   // 3 vertices * 3 coordinates
    GLfloat colors[12];    // 3 vertices * 4 color components
    GLfloat position[2];   // Offset position for the object
};