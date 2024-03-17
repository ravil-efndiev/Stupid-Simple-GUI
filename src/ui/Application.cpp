#include "Application.hpp"
#include <glad/glad.h>

namespace ssg {
    Application::Application(const WindowParams& wndParams, bool setupDockspace) {
        window = std::make_unique<Window>(wndParams.Width, wndParams.Height, wndParams.Title);
    }

    Status Application::start() {
        init();

        while (!window->shouldClose()) {
            glClearColor(0.2f, 0.6f, 0.2f, 1.f);
            glClear(GL_COLOR_BUFFER_BIT);

            renderUI();

            window->swapBuffers();
            window->pollEvents();
        }

        return Status::Success;
    }
}
