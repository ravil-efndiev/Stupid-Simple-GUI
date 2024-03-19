#pragma once
#include "Core.hpp"
#include <imgui.h>

struct GLFWwindow;

namespace ssgui {
    class ImGuiControlls {
    public:
        static void init(GLFWwindow* window);    
        static void setStyle(const std::function<void(ImGuiIO&, ImGuiStyle&)>& styleFunc);    
        static void setStandartStyle(ImGuiIO& io, ImGuiStyle& style);
        static void shutdown();
        static void runDockspace();
        static void newFrame();
        static void render();

        static std::unordered_map<std::string, ImFont*> Fonts;
    };
}
