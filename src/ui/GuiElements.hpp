#pragma once

#include "Core.hpp"
#include "Vector.hpp"

namespace ssgui {
	void beginMainWindow();
	void endMainWindow();

	void dragVec3(const std::string& label, Vector3* values, std::array<char, 3> elementNames = {'X', 'Y', 'Z'}, f32 columnWidth = 100.0f);
	void dragVec2(const std::string& label, Vector2* values, std::array<char, 2> elementNames = {'X', 'Y'}, f32 columnWidth = 100.0f);

	void dragFloat(const std::string& label, f32* value, f32 columnWidth = 100.0f);
	void dragInt(const std::string& label, i32* value, f32 columnWidth = 100.0f);

    std::string openFileDialogButton(const std::string& label, const char* extFilter, const char* startPath = nullptr);    
    std::string saveFileDialogButton(const std::string& label, const char* extFilter, const char* startPath = nullptr);    

}
