#include "Application.hpp"

namespace ssg {
    Application::Application(const WindowParams& wndParams, bool setupDockspace) {
        window = std::make_unique<Window>(wndParams.Width, wndParams.Height, wndParams.Title);
    }

    Status Application::start() {
        init();

        while (!window->shouldClose()) {
            renderUI();

            window->swapBuffers();
            window->pollEvents();
        }

        return Status::Success;
    }
}
