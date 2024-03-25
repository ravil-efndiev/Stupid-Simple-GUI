#pragma once
#include "Core.hpp"
#include "Vector.hpp"
#include <imgui.h>

namespace ssgui {
    // style properties for buttons
    struct ButtonStyle {
        ImFont* Font;
        // text color for the button
        std::optional<Vector4> Color = std::nullopt;

        // background color when button is not interracted with
        std::optional<Vector4> BackgroundColor = std::nullopt;

        // background color when button is hovered by the mouse
        std::optional<Vector4> HoverColor = std::nullopt;

        // background color when button is clicked
        std::optional<Vector4> ClickedColor = std::nullopt;
        f32 Alignment = 0.f;
    };

    // style properties for text elements
    struct TextStyle {
        ImFont* Font;
        std::optional<Vector4> Color = std::nullopt;
        f32 Alignment = 0.f;
    };

    // style properties for text inputs elements
    struct InputTextStyle {
        ImFont* Font;

        // Text Color
        std::optional<Vector4> Color = std::nullopt;

        // Background Color
        std::optional<Vector4> BackgroundColor = std::nullopt;
        f32 Alignment = 0.f;
        f32 Width = 0.f;
    };
}
