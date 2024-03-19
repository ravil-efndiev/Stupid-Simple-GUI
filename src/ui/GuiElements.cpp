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

	void dragVec3(const std::string& label, Vector3* values, std::array<char, 3> elementNames, float columnWidth) {
        std::string labelDisp = splitStr(label, '#').front();
		ImGui::PushID(label.c_str());

		ImGui::Columns(2);
		ImGui::SetColumnWidth(0, columnWidth);
		ImGui::Text("%s", labelDisp.c_str());
		ImGui::NextColumn();

		ImGui::PushMultiItemsWidths(3, ImGui::CalcItemWidth());

        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4.0f, 2.0f));
        ImGui::Text("%c", elementNames[0]);
		ImGui::SameLine();
		ImGui::DragFloat("##drag_x", &values->x, 0.1f, 0.f, 0.f, "%.2f");
		ImGui::PopItemWidth();
		ImGui::SameLine();

        ImGui::Text("%c", elementNames[1]);
		ImGui::SameLine();
		ImGui::DragFloat("##drag_y", &values->y, 0.1f, 0.f, 0.f, "%.2f");
		ImGui::PopItemWidth();
		ImGui::SameLine();

        ImGui::Text("%c", elementNames[2]);
		ImGui::SameLine();
		ImGui::DragFloat("##drag_z", &values->z, 0.1f, 0.f, 0.f, "%.2f");
		ImGui::PopItemWidth();

		ImGui::PopStyleVar();

		ImGui::Columns(1);
		ImGui::PopID();
	}

    void dragVec2(const std::string& label, Vector2* values, std::array<char, 2> elementNames, float columnWidth) {
        std::string labelDisp = splitStr(label, '#').front();
		ImGui::PushID(label.c_str());

		ImGui::Columns(2);
		ImGui::SetColumnWidth(0, columnWidth);
		ImGui::Text("%s", labelDisp.c_str());
		ImGui::NextColumn();

		ImGui::PushMultiItemsWidths(2, ImGui::CalcItemWidth());

        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4.0f, 2.0f));
        ImGui::Text("%c", elementNames[0]);
		ImGui::SameLine();
		ImGui::DragFloat("##drag_x", &values->x, 0.1f, 0.f, 0.f, "%.2f");
		ImGui::PopItemWidth();
		ImGui::SameLine();

        ImGui::Text("%c", elementNames[1]);
		ImGui::SameLine();
		ImGui::DragFloat("##drag_y", &values->y, 0.1f, 0.f, 0.f, "%.2f");
		ImGui::PopItemWidth();
		ImGui::SameLine();
		ImGui::PopStyleVar();

		ImGui::Columns(1);
		ImGui::PopID();
    }

    void dragFloat(const std::string& label, float* value, float columnWidth) {
        std::string labelDisp = splitStr(label, '#').front();

		ImGui::PushID(label.c_str());
		ImGui::Columns(2);
        
		ImGui::SetColumnWidth(0, columnWidth);
		ImGui::Text("%s", labelDisp.c_str());
		ImGui::NextColumn();
        
		ImGui::PushItemWidth(ImGui::CalcItemWidth() / 2.f);

        ImGui::Text(" ");
		ImGui::SameLine();
		ImGui::DragFloat("##float", value, 0.1f, 0.f, 0.f, "%.2f");
		ImGui::PopItemWidth();

		ImGui::Columns(1);
		ImGui::PopID();
    }

	void dragInt(const std::string& label, int* value, float columnWidth) {
		std::string labelDisp = splitStr(label, '#').front();

		ImGui::PushID(label.c_str());
		ImGui::Columns(2);
        
		ImGui::SetColumnWidth(0, columnWidth);
		ImGui::Text("%s", labelDisp.c_str());
		ImGui::NextColumn();
        
		ImGui::PushItemWidth(ImGui::CalcItemWidth() / 2.f);

        ImGui::Text(" ");
		ImGui::SameLine();
		ImGui::DragInt("##int", value);
		ImGui::PopItemWidth();

		ImGui::Columns(1);
		ImGui::PopID();
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

}
