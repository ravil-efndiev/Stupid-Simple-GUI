#pragma once
#include "Window.hpp"

#define SS_APPLICATION(Type) std::unique_ptr<Application> createApp() {return std::make_unique<Type>()}

namespace ssg {
    struct WindowParams {
        u16 Width;
        u16 Height;
        std::string Title;
    };

    class Application {
    public:
        Application(const WindowParams& wndParams, bool setupDockspace);
        virtual ~Application() {}

        virtual void init() = 0;
        virtual void renderUI() = 0;

        Status start();

    private:
        std::unique_ptr<Window> window;

    };

    extern std::unique_ptr<Application> createApp();

}

