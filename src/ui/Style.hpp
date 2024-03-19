#pragma once
#include "Core.hpp"
#include "Vector.hpp"
#include <imgui.h>

namespace ssgui {
    struct ButtonStyle {
        ImFont* Font;
        std::optional<Vector4> Color = std::nullopt;
        std::optional<Vector4> BackgroundColor = std::nullopt;
        std::optional<Vector4> HoverColor = std::nullopt;
        std::optional<Vector4> ClickedColor = std::nullopt;
        f32 Alignment = 0.f;
    };

    struct TextStyle {
        ImFont* Font;
        std::optional<Vector4> Color = std::nullopt;
        f32 Alignment = 0.f;
    };
}
