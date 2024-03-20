#include "GuiElements.hpp"
#include "Application.hpp"
#include "General.hpp"
#include <nfd.h>
#include <imgui.h>
#include <imgui_internal.h>

namespace ssgui {
    void beginMainWindow() {
        static ImGuiWindowFlags mainFlags =
            ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse
            | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove
            | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoScrollbar
            | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollWithMouse;

        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        Application* app = Application::Get();

        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        ImGui::PushStyleColor(ImGuiCol_WindowBg, app->BackgroundColor.asImgui());
        ImGui::Begin("MainWindow", nullptr, mainFlags);
    }

    void endMainWindow() {
        ImGui::End();
        ImGui::PopStyleVar();
        ImGui::PopStyleColor();
    }

    std::string openFileDialogButton(const std::string& label, const char* extFilter, const char* startPath) {
        if (ImGui::Button(label.c_str())) {
            return openFileDialog(extFilter, startPath);
        }
        return {};
    }

    std::string saveFileDialogButton(const std::string& label, const char* extFilter, const char* startPath) {
        if (ImGui::Button(label.c_str())) {
            return saveFileDialog(extFilter, startPath);
        }
        return {};
    }

    Status progressBar(const std::string& label, f32 value, const ImVec2& size, ImU32 bgcol, ImU32 fgcol) {
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        if (window->SkipItems) return Status_Error;

        ImGuiContext& ctx = *GImGui;
        ImGuiStyle style = ctx.Style;
        ImGuiID id = window->GetID(label.c_str());

        ImVec2 pos = window->DC.CursorPos;
        auto [width, height] = size;
        width -= style.FramePadding.x * 2;

        ImRect barBounds(pos, ImVec2(pos.x + width, pos.y + height));
        ImGui::ItemSize(barBounds, style.FramePadding.y);
        bool added = ImGui::ItemAdd(barBounds, id);

        if (!added) return Status_Error;

        window->DrawList->AddRectFilled(barBounds.Min, ImVec2(pos.x + width, barBounds.Max.y), bgcol);
        window->DrawList->AddRectFilled(barBounds.Min, ImVec2(pos.x + width * value, barBounds.Max.y), fgcol);
        return Status_Success;
    }
}
