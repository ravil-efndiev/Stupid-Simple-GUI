#include "GuiElements.hpp"
#include "Application.hpp"
#include "General.hpp"
#include <nfd.h>
#include <imgui.h>
#include <imgui_internal.h>

namespace ssgui {
    void alignWidget(const char* label, f32 alignment) {
		ImGuiStyle& style = ImGui::GetStyle();

		f32 winSize = ImGui::GetContentRegionAvail().x;
		f32 size = ImGui::CalcTextSize(label).x + style.FramePadding.x * 2.f;

		f32 off = (winSize - size) * alignment;
		if (off > 0.f)
			ImGui::SetCursorPosX(ImGui::GetCursorPosX() + off);
	}

	void alignWidget(f32 width, f32 alignment) {
		ImGuiStyle& style = ImGui::GetStyle();

		f32 winSize = ImGui::GetContentRegionAvail().x;
		f32 size = width + style.FramePadding.x * 2.f;

		f32 off = (winSize - size) * alignment;
		if (off > 0.f)
			ImGui::SetCursorPosX(ImGui::GetCursorPosX() + off);
	}

	void textAligned(const char* text, f32 alignment) {
		ImGui::Dummy({0.f, 0.f});
		f32 winSize = ImGui::GetContentRegionAvail().x;
		f32 size = ImGui::CalcTextSize(text).x;

		f32 indentation = (winSize - size) * alignment;

		f32 minIndentation = 20.0f;
		if (indentation <= minIndentation) {
			indentation = minIndentation;
		}

		ImGui::SameLine(indentation);
		ImGui::PushTextWrapPos(winSize - indentation);
		ImGui::TextWrapped("%s", text);
		ImGui::PopTextWrapPos();
	}

    bool buttonStyled(const std::string& label, const Vector2& size, const ButtonStyle& style) {
		u16 numColors = 0;

		alignWidget(label.c_str(), style.Alignment);
		if (style.Color) {
			ImGui::PushStyleColor(ImGuiCol_Text, style.Color->asImgui());
			numColors++;
		}
		if (style.BackgroundColor) {
			ImGui::PushStyleColor(ImGuiCol_Button, style.BackgroundColor->asImgui());
			numColors++;
		}
		if (style.HoverColor) {
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, style.HoverColor->asImgui());
			numColors++;
		}
		if (style.ClickedColor) {
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, style.ClickedColor->asImgui());
			numColors++;
		}
		
		if (style.Font)	ImGui::PushFont(style.Font);
		bool clicked = ImGui::Button(label.c_str(), size.asImgui()); 
		if (numColors > 0) ImGui::PopStyleColor(numColors);
		if (style.Font) ImGui::PopFont();
		return clicked;
    }

    void textStyled(const std::string& text, const TextStyle& style) {
		if (style.Font)	ImGui::PushFont(style.Font);
		if (style.Color) ImGui::PushStyleColor(ImGuiCol_Text, style.Color->asImgui());
		
		textAligned(text.c_str(), style.Alignment);

		if (style.Color) ImGui::PopStyleColor();
		if (style.Font) ImGui::PopFont();
    }

    void inputTextStyled(const std::string& label, std::string* string, const InputTextStyle& style) {
		if (style.Font)	ImGui::PushFont(style.Font);
		if (style.Color) ImGui::PushStyleColor(ImGuiCol_Text, style.Color->asImgui());
		if (style.BackgroundColor) ImGui::PushStyleColor(ImGuiCol_FrameBg, style.BackgroundColor->asImgui());
		if (style.Width > 0) ImGui::PushItemWidth(style.Width);

		ImGui::SetCursorPosX(INVISIBLE_AREA_X);
		ImGui::InputText(label.c_str(), string);
		f32 width = ImGui::GetItemRectSize().x;
		ImGui::SetCursorPosX(0.f);
		alignWidget(width, style.Alignment);
		ImGui::InputText(label.c_str(), string);

		if (style.Width > 0) ImGui::PopItemWidth();
		if (style.Color) ImGui::PopStyleColor();
		if (style.BackgroundColor) ImGui::PopStyleColor();
		if (style.Font) ImGui::PopFont();
    }
}
