#include "Window.hpp"
#include <glad/glad.h>
#include <glfw/glfw3.h>

namespace ssg {
    Window::Window(u16 width, u16 height, const std::string& title) : title(title) {
        initGlfw();
        createWindow(width, height);   
    }

    Window::~Window() {
        glfwTerminate();
    }
    
    void Window::initGlfw() {
        bool initSuccess = glfwInit();

        SS_ASSERT(initSuccess, "failed to init glfw")

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
    
    void Window::createWindow(u16 width, u16 height) {
        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        SS_ASSERT(window, "failed to create glfw window");

        glfwMakeContextCurrent(window);

        bool gladInitSuccess = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        SS_ASSERT(gladInitSuccess, "failed to init glad")
    }

    bool Window::shouldClose() const {
        return glfwWindowShouldClose(window);
    }

    void Window::swapBuffers() {
        glfwSwapBuffers(window);
    }

    void Window::pollEvents() {
        glfwPollEvents();
    }

}
