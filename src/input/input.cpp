#include "input.h"

Input::Input(GLFWwindow* window) {
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, keyCallback);
}

Input::~Input() {
}

bool Input::isKeyPressed(Key key) {
    return m_keys[key];
}

void Input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Input* input = static_cast<Input*>(glfwGetWindowUserPointer(window));

    if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_UP:
                input->m_keys[Key::UP] = true;
                break;
            case GLFW_KEY_DOWN:
                input->m_keys[Key::DOWN] = true;
                break;
            case GLFW_KEY_LEFT:
                input->m_keys[Key::LEFT] = true;
                break;
            case GLFW_KEY_RIGHT:
                input->m_keys[Key::RIGHT] = true;
                break;
            case GLFW_KEY_ESCAPE:
                input->m_keys[Key::ESC] = true;
        }
    } else if (action == GLFW_RELEASE) {
        switch (key) {
            case GLFW_KEY_UP:
                input->m_keys[Key::UP] = false;
                break;
            case GLFW_KEY_DOWN:
                input->m_keys[Key::DOWN] = false;
                break;
            case GLFW_KEY_LEFT:
                input->m_keys[Key::LEFT] = false;
                break;
            case GLFW_KEY_RIGHT:
                input->m_keys[Key::RIGHT] = false;
                break;
            case GLFW_KEY_ESCAPE:
                input->m_keys[Key::ESC] = false;
        }
    }
}