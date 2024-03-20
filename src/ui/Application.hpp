#pragma once
#include "Window.hpp"
#include "Vector.hpp"
#include <imgui.h>

#define SS_APPLICATION(Type) \
    void createApp() {Application::Create<Type>();}

namespace ssgui {

    /**
     * @brief Parameters for window (Width, Height, Display title)
     */
    struct WindowParams {
        u16 Width;
        u16 Height;
        std::string Title;
    };

    /**
     * @brief Base class for ssgui applications
     * @note Contains methods to interract with lower level APIs
     */
    class Application {
    public:
        /**
         * @brief Static method to create instance of Application, can be max of 1 instance (unique_ptr)
         * @tparam AppT your application class derived from main Application
         * @param ...args Constructor arguments for your class
         */
        template<class AppT, class... Args>
        static void Create(Args&&... args) {
            if (!App)
                App = std::make_unique<AppT>(std::forward<Args>(args)...);
        }

        /**
         * @brief Static method to get current application instance 
         * @return Raw pointer to the application instance
         */
        static Application* Get() {return App.get();}
    
        /**
         * @brief Application base class constructor
         * @param wndParams Window data sepcified in WindowParams struct
         * @param useDockspace Flag to use ImGui dockspace for your application
         */
        Application(const WindowParams& wndParams, bool useDockspace = true);
        virtual ~Application() {}

        /**
         * @brief Virtual method that must be implemented by Application child 
         * @note Called once when app starts
         */
        virtual void init() = 0;
        
        /**
         * @brief Virtual method that must be implemented by Application child
         * @note Called every frame, use it to render ImGui UI and custom UI elements
         */
        virtual void renderUI() = 0;

        /**
         * @brief starts application in main Function
         * @return application exit code
         * @note DO NOT USE IT INSIDE YOUR PROGRAM, it is handeled for you
         */
        Status start();

        /**
         * @brief Sets ImGui style variables
         * @param styleFunc Function that takes ImGuiIO& and ImGuiStyle& in which you can setup style variables
         */
        void setImGuiStyle(const std::function<void(ImGuiIO&, ImGuiStyle&)>& styleFunc);

        /**
         * @brief Adds font to global fonts collection
         * @param name name of font to access it later
         * @param pathTTF path to the TTF file containing the font
         * @param sizePixels size of font in pixels
         * @return pointer to ImFont that has been created
         */
        ImFont* addFont(const std::string& name, const std::string& pathTTF, f32 sizePixels);

        /**
         * @brief Gets font from global fonts collection
         * @param name name of the font
         * @return pointer to ImFont under `name` parameter in the collection
         */
        ImFont* getFont(const std::string& name);

        /**
         * @brief Specifies if you want to use ImGui dockspace
         */
        bool UseDockspace;
        
        /**
         * @brief Color that is used to clear screen with in OpenGL
         * @note also used as background color in `mainWindow` element
         */
        Vector4 BackgroundColor;

    private:
        std::unique_ptr<Window> window;

        static std::unique_ptr<Application> App;
    };

    /**
     * @brief function you must implement to specift Application class instance
     * @note must call Application::Create<YourAppClass>(...constructor arguments)
     * @note can be implemented automatically using SS_APPLICATION(YourAppClass) macro, if your class
     * @note constructor doesn't take any arguments
     */
    extern void createApp();

}

