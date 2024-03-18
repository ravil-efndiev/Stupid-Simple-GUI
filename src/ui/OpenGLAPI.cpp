#include "OpenGLAPI.hpp"
#include <glad/glad.h>

namespace ssgui {
    void OpenGLAPI::clear(const Vector4& color) {
        glClearColor(color.r, color.g, color.b, color.a);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    
    Vector2i OpenGLAPI::getViewport() {
        i32 viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);
        return {viewport[2], viewport[3]};
    }   

    void OpenGLAPI::setViewport(const Vector2i& size) {
        glViewport(0, 0, size.x, size.y);
    }

}
