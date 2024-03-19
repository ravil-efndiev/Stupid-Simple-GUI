#pragma once

#include "Core.hpp"
#include "Vector.hpp"
#include "Style.hpp"

namespace ssgui {
	static constexpr f32 ALLIGN_CENTER = 0.5f;
	static constexpr f32 ALLIGN_RIGHT = 1.0f;

	void beginMainWindow();
	void endMainWindow();

	void dragVec3(const std::string& label, Vector3* values, std::array<char, 3> elementNames = {'X', 'Y', 'Z'}, f32 columnWidth = 100.0f);
	void dragVec2(const std::string& label, Vector2* values, std::array<char, 2> elementNames = {'X', 'Y'}, f32 columnWidth = 100.0f);

	void dragFloat(const std::string& label, f32* value, f32 columnWidth = 100.0f);
	void dragInt(const std::string& label, i32* value, f32 columnWidth = 100.0f);

    std::string openFileDialogButton(const std::string& label, const char* extFilter, const char* startPath = nullptr);    
    std::string saveFileDialogButton(const std::string& label, const char* extFilter, const char* startPath = nullptr);    

	Status progressBar(const std::string& label, f32 value,  const ImVec2& size, ImU32 bgcol, ImU32 fgcol);

	void alignWidget(const char* label, f32 alignment);
	void textAligned(const char* text, f32 alignment);

	bool buttonStyled(const std::string& label, const Vector2& size = {}, const ButtonStyle& style = {});
	void textStyled(const std::string& text, const TextStyle& style);
}
