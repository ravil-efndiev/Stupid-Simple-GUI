#pragma once
#include "Core.hpp"

namespace ssg {
    class Window {
    public:
        Window(u16 width, u16 height, const std::string& title);
        ~Window();

        bool shouldClose() const;
        void swapBuffers();
        void pollEvents();

    private:
        void initGlfw();
        void createWindow(u16 width, u16 height);

    private:
        GLFWwindow* window;
        std::string title;
    };
}

