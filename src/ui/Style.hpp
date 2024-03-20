#pragma once
#include "Core.hpp"
#include "Vector.hpp"
#include <imgui.h>

namespace ssgui {
    // style properties for buttons
    struct ButtonStyle {
        // ImGui font for the button label
        ImFont* Font;
        // text color for the button
        std::optional<Vector4> Color = std::nullopt;

        // background color when button is not interracted with
        std::optional<Vector4> BackgroundColor = std::nullopt;

        // background color when button is hovered by the mouse
        std::optional<Vector4> HoverColor = std::nullopt;

        // background color when button is clicked
        std::optional<Vector4> ClickedColor = std::nullopt;

        // button alignment on horizontal axis(0.0f - 1.0f)
        f32 Alignment = 0.f;
    };

    // style properties for text elements
    struct TextStyle {
        // ImGui font for the text label
        ImFont* Font;

        // Text Color
        std::optional<Vector4> Color = std::nullopt;

        // text alignment on horizontal axis(0.0f - 1.0f)
        f32 Alignment = 0.f;
    };
}
