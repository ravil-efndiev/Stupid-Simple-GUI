#pragma once
#include "Window.hpp"
#include "Vector.hpp"
#include <imgui.h>

#define SS_APPLICATION(Type) \
    void createApp() {Application::Create<Type>();}

namespace ssgui {
    struct WindowParams {
        u16 Width;
        u16 Height;
        std::string Title;
    };

    class Application {
    public:
        template<class AppT, class... Args>
        static void Create(Args&&... args) {
            App = std::make_unique<AppT>(args...);
        }

        static Application* Get() {return App.get();}
    
        Application(const WindowParams& wndParams, bool setupDockspace);
        virtual ~Application() {}

        virtual void init() = 0;
        virtual void renderUI() = 0;

        Status start();

        void setClearColor(const Vector4& color);
        void setImGuiStyle(const std::function<void(ImGuiIO&, ImGuiStyle&)>& styleFunc);

    private:
        std::unique_ptr<Window> window;
        Vector4 clearColor;
        static std::unique_ptr<Application> App;
    };

    extern void createApp();

}

