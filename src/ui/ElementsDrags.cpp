#include "GuiElements.hpp"
#include "Application.hpp"
#include "General.hpp"
#include <nfd.h>
#include <imgui.h>
#include <imgui_internal.h>

namespace ssgui {
	void dragVec3(const std::string& label, Vector3* values, std::array<char, 3> elementNames, f32 columnWidth) {
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

    void dragVec2(const std::string& label, Vector2* values, std::array<char, 2> elementNames, f32 columnWidth) {
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

    void dragFloat(const std::string& label, f32* value, f32 columnWidth) {
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

	void dragInt(const std::string& label, i32* value, f32 columnWidth) {
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
}
