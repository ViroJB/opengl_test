#include "game.h"

Game::Game() {
    m_glfwManager.initialize();

    m_window = m_glfwManager.createWindow(800, 600, "OpenGL Triangle");
    glfwMakeContextCurrent(m_window);

    m_glewManager.initialize();
    m_bufferManager.setupBuffers(m_VAO, m_VBO);

    m_renderer = new Renderer();
    m_input = new Input(m_window);

    glEnable(GL_BLEND);                                 // enable blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  // enable transparency

    // note temp stuff
    RenderableObject obj1 = {{-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f},  // Vertices
                             {1.0f, 0.0f, 0.0f, 1.0f,                                    // Color for first vertex (red)
                              0.0f, 1.0f, 0.0f, 1.0f,                                    // Color for second vertex (green)
                              0.0f, 0.0f, 1.0f, 1.0f},                                   // Color for third vertex (blue)
                             {0.0f, 0.0f}};                                              // Position

    RenderableObject obj2 = {{-0.75f, 0.75f, 0.0f, 0.75f, 0.75f, 0.0f, 0.0f, -0.75f, 0.0f},  // Vertices
                             {0.0f, 1.0f, 0.0f, 0.3f,                                        // Color for first vertex (green)
                              0.0f, 0.0f, 1.0f, 0.3f,                                        // Color for second vertex (blue)
                              1.0f, 1.0f, 0.0f, 0.3f},                                       // Color for third vertex (yellow)
                             {0.0f, 0.0f}};                                                  // Position

    RenderableObject obj3 = {{-0.1f, -0.1f, 0.0f, 0.1f, -0.1f, 0.0f, 0.0f, 0.1f, 0.0f},  // Vertices
                             {1.0f, 1.0f, 0.0f, 1.0f,                                    // Color for first vertex (yellow)
                              1.0f, 1.0f, 0.0f, 1.0f,                                    // Color for second vertex (yellow)
                              1.0f, 1.0f, 0.0f, 1.0f},                                   // Color for third vertex (yellow)
                             {0.7f, 0.7f}};                                              // Position

    RenderableObject obj4 = { // first triangle of square
                             {
                                 -0.9f, 0.9f, 0.0f,  // top left
                                 -0.7f, 0.9f, 0.0f,  // top right
                                 -0.9f, 0.7f, 0.0f   // bottom left
                             },
                             {
                                 1.0f, 0.0f, 0.0f, 1.0f,  // red
                                 0.0f, 1.0f, 0.0f, 1.0f,  // green
                                 0.0f, 0.0f, 1.0f, 1.0f   // blue
                             },
                             {0.0f, 0.0f}};

    RenderableObject obj5 = { // second triangle of square
                             {
                                 -0.7f, 0.9f, 0.0f,  // top right
                                 -0.7f, 0.7f, 0.0f,  // bottom right
                                 -0.9f, 0.7f, 0.0f   // bottom left
                             },
                             {
                                 0.0f, 1.0f, 0.0f, 1.0f,  // green
                                 1.0f, 1.0f, 0.0f, 1.0f,  // yellow
                                 0.0f, 0.0f, 1.0f, 1.0f   // blue
                             },
                             {0.0f, 0.0f}};

    m_renderObjects.push_back(obj1);
    m_renderObjects.push_back(obj2);
    m_renderObjects.push_back(obj3);
    m_renderObjects.push_back(obj4);
    m_renderObjects.push_back(obj5);
}

void Game::run() {
    // m_renderer.setShaderProgram(m_shaderProgram);
    while (!glfwWindowShouldClose(m_window)) {
        // get input
        if (m_input->isKeyPressed(Input::Key::UP)) {
            fmt::print("UP key pressed\n");
            m_renderObjects[0].position[1] += 0.01f;
        }
        if (m_input->isKeyPressed(Input::Key::DOWN)) {
            fmt::print("DOWN key pressed\n");
            m_renderObjects[0].position[1] -= 0.01f;
        }
        if (m_input->isKeyPressed(Input::Key::LEFT)) {
            fmt::print("LEFT key pressed\n");
            m_renderObjects[0].position[0] -= 0.01f;
        }
        if (m_input->isKeyPressed(Input::Key::RIGHT)) {
            fmt::print("RIGHT key pressed\n");
            m_renderObjects[0].position[0] += 0.01f;
        }
        // close on esc
        if (m_input->isKeyPressed(Input::Key::ESC)) {
            fmt::print("ESC key pressed\n");
            glfwSetWindowShouldClose(m_window, 1);
        }

        // update gamestate

        // render
        m_renderer->render(m_window, m_renderObjects, m_VAO, m_VBO);

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}

void Game::cleanup() {
    m_bufferManager.cleanup(m_VAO, m_VBO);
    // glDeleteProgram(m_shaderProgram);
    glfwDestroyWindow(m_window);
    glfwTerminate();
}