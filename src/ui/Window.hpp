#pragma once
#include "Core.hpp"

struct GLFWwindow;

namespace ssgui {
    class Window {
    public:
        Window(u16 width, u16 height, const std::string& title);
        ~Window();

        bool shouldClose() const;
        void swapBuffers();
        void pollEvents();

        GLFWwindow* getWindowPtr();

    private:
        void initGlfw();
        void createWindow(u16 width, u16 height);
        void setupEvents();

    private:
        GLFWwindow* window;
        std::string title;
    };
}

