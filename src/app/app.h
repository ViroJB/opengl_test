#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fmt/core.h>

#include <iostream>

#include "../render/renderer.h"
#include "../managers/buffer_manager.h"
#include "../managers/glfw_manager.h"
#include "../managers/glew_manager.h"
#include "../managers/shader_manager.h"
#include "../game/game.h"

class App {
   public:
    App();
    ~App();

   private:
};
