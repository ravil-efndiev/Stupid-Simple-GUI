#pragma once

#include "Core.hpp"
#include "Vector.hpp"
#include "Style.hpp"

namespace ssgui {
	// alignment constant for elements to center them horrizontally
	static constexpr f32 ALLIGN_CENTER = 0.5f;
	// alignment constant for elements to align them to the right
	static constexpr f32 ALLIGN_RIGHT = 1.0f;

	/**
	 * @brief begins MainWindow element
	 * @note it takes up all the screen and uses Application::BackgroundColor as its background color
	 */
	void beginMainWindow();
	// ends MainWindow element
	void endMainWindow();

	/**
	 * @brief custom selector for 3 floats
	 * @param label label of the drag (can use ImGui style ## to specify name)
	 * @param values Vector3 pointer to change values of
	 * @param elementNames displayed names of elements (X Y Z) by default, can be set to any array of 3 characters
	 * @param columnWidth width of vector element selector column
	 */
	void dragVec3(const std::string& label, Vector3* values, std::array<char, 3> elementNames = {'X', 'Y', 'Z'}, f32 columnWidth = 100.0f);
	/**
	 * @brief custom selector for 2 floats
	 * @param label label of the drag (can use ImGui style ## to specify name)
	 * @param values Vector2 pointer to change values of
	 * @param elementNames displayed names of elements (X Y) by default, can be set to any array of 2 characters
	 * @param columnWidth width of vector element selector column
	 */
	void dragVec2(const std::string& label, Vector2* values, std::array<char, 2> elementNames = {'X', 'Y'}, f32 columnWidth = 100.0f);

	/**
	 * @brief custom selector for 1 float
	 * @param label label of the drag (can use ImGui style ## to specify name)
	 * @param values float pointer to the value
	 * @param columnWidth width of selector column
	 */
	void dragFloat(const std::string& label, f32* value, f32 columnWidth = 100.0f);
	/**
	 * @brief custom selector for 1 int
	 * @param label label of the drag (can use ImGui style ## to specify name)
	 * @param values int pointer to the value
	 * @param columnWidth width of selector column
	 */
	void dragInt(const std::string& label, i32* value, f32 columnWidth = 100.0f);

    /**
     * @brief creates ImGui button that opens nfd open file dialig when clicked
     * @param label label of the button
     * @param extFilter file extension filter (txt|png)
     * @param startPath path to start file dialog at (last used path if set to nullptr)
     * @return path to the selected file when button was clicked and dialog succeeded
     */
    std::string openFileDialogButton(const std::string& label, const char* extFilter, const char* startPath = nullptr);    
    /**
     * @brief creates ImGui button that opens nfd save file dialig when clicked
     * @param label label of the button
     * @param extFilter file extension filter (txt|png)
     * @param startPath path to start file dialog at (last used path if set to nullptr)
     * @return path to the file user wants to create when button was clicked and dialog succeeded
     * @note function does not create a file, only returns a path to where user wants to create it
     */
    std::string saveFileDialogButton(const std::string& label, const char* extFilter, const char* startPath = nullptr);    

	/**
	 * @brief custom progress bar element
	 * @param label identifier (is not displayed)
	 * @param value value of progress bar in range of (0.0f - 1.0f)
	 * @param size width and height of progress bar
	 * @param bgcol background color (use IM_COL32() to set it)
	 * @param fgcol foreground color (use IM_COL32() to set it)
	 * @return exit status
	 */
	Status progressBar(const std::string& label, f32 value,  const ImVec2& size, ImU32 bgcol, ImU32 fgcol);

	/**
	 * @brief aligns labeled widget horrizontally
	 * @param label widget label to calculate it's size
	 * @param alignment alignment on horizontal axis, (0.0f - 1.0f) where 0 is full left and 1 is full right
	 */
	void alignWidget(const char* label, f32 alignment);

	/**
	 * @brief ImGui button with custom style properties
	 * @param label label of the button
	 * @param size size of the button (set it to default to automatically size it)
	 * @param style struct `ButtonStyle` that contains style properties for the button
	 * @return true when button is clicked
	 * @note style from `style` argument is applied by normal ImGui Push functions
	 * @note ssgui styles are just more readeable and easier to use abstractions
	 */
	bool buttonStyled(const std::string& label, const Vector2& size = {}, const ButtonStyle& style = {});

	/**
	 * @brief ImGui text with custom style properties
	 * @param text text to display
	 * @param style struct `TextStyle` that contains style properties for the text
	 * @note style from `style` argument is applied by normal ImGui Push functions
	 * @note ssgui styles are just more readeable and easier to use abstractions
	 */
	void textStyled(const std::string& text, const TextStyle& style);

	/**
	 * @brief ImGui text with alignment value
	 * @param text text to display
	 * @param alignment alignment on horizontal axis, (0.0f - 1.0f) where 0 is full left and 1 is full right
	 */
	void textAligned(const char* text, f32 alignment);
}
