#pragma once
#include "Core.hpp"

struct GLFWwindow;
class ImGuiStyle;
class ImGuiIO;

namespace ssgui {
    void setStandartStyle(ImGuiIO& io, ImGuiStyle& style);
    void initImgui(GLFWwindow* window);    
    void setImguiStyle(const std::function<void(ImGuiIO&, ImGuiStyle&)>& styleFunc);    
    void shutdownImgui();
    void imguiDockspace();
    void imguiNewFrame();
    void renderImgui();
}
