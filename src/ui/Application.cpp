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
        ImGuiControlls::init(window->getWindowPtr());
        init();

        while (!window->shouldClose()) {
            OpenGLAPI::clear(BackgroundColor);

            ImGuiControlls::newFrame();
            if (UseDockspace)
                ImGuiControlls::runDockspace();
                
            renderUI();
            ImGuiControlls::render();

            window->swapBuffers();
            window->pollEvents();
        }

        ImGuiControlls::shutdown();

        return Status_Success;
    }

    void Application::setImGuiStyle(const std::function<void(ImGuiIO&, ImGuiStyle&)>& styleFunc) {
        ImGuiControlls::setStyle(styleFunc);
    }
    
    ImFont* Application::addFont(const std::string& name, const std::string& pathTTF, f32 sizePixels) {
        ImGuiIO& io = ImGui::GetIO();
        ImFont* font = io.Fonts->AddFontFromFileTTF(pathTTF.c_str(), sizePixels);
        ImGuiControlls::Fonts.emplace(name, font);
        return font;
    }
    
    ImFont* Application::getFont(const std::string& name) {
        try {
            return ImGuiControlls::Fonts.at(name);
        }
        catch (std::out_of_range) {
            return nullptr;
        }
    }
}
