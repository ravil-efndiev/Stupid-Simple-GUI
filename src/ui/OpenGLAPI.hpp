#pragma once
#include "Vector.hpp"

namespace ssgui {
    class OpenGLAPI {
    public:
        static void clear(const Vector4& color);
        static Vector2i getViewport();
        static void setViewport(const Vector2i& size);
    };
}
