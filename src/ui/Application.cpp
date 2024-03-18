#include "Application.hpp"
#include "OpenGLAPI.hpp"
#include "ImguiControlls.hpp"

namespace ssgui {
    std::unique_ptr<Application> Application::App;

    Application::Application(const WindowParams& wndParams, bool useDockspace) 
        : UseDockspace(useDockspace) {
        window = std::make_unique<Window>(wndParams.Width, wndParams.Height, wndParams.Title);
    }

    Status Application::start() {
        initImgui(window->getWindowPtr());
        init();

        while (!window->shouldClose()) {
            OpenGLAPI::clear(clearColor);

            imguiNewFrame();
            if (UseDockspace)
                imguiDockspace();
                
            renderUI();
            renderImgui();

            window->swapBuffers();
            window->pollEvents();
        }

        shutdownImgui();

        return Status_Success;
    }

    void Application::setClearColor(const Vector4& color) {
        clearColor = color;
    }

    void Application::setImGuiStyle(const std::function<void(ImGuiIO&, ImGuiStyle&)>& styleFunc) {
        setImguiStyle(styleFunc);
    }
}
