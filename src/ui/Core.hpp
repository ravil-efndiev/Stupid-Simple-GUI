#pragma once
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <optional>
#include <stdlib.h>

#include <imgui.h>
#include <misc/cpp/imgui_stdlib.h>

#define SS_ASSERT(condition, errorText) if (!(condition)) {printErr(errorText); exit(Status_Error);}

namespace ssgui {
    typedef int8_t  i8;
    typedef int16_t i16;
    typedef int32_t i32;
    typedef int64_t i64;

    typedef uint8_t  u8;
    typedef uint16_t u16;
    typedef uint32_t u32;
    typedef uint64_t u64;

    typedef float  f32;
    typedef double f64;

    // exit status enum for different API functions
    enum Status {
        Status_Success = 0,
        Status_Error = 1,
    };

    /**
     * @brief prints formatted text to stdout with newline at the end
     * @param fmt c-style format string
     * @param ...args format arguments
     */
    template <class... Args>
    void print(const std::string& fmt, Args&&... args) {
        std::string fmtout = fmt + "\n";
        (void)printf(fmtout.c_str(), std::forward<Args>(args)...);
    }

    /**
     * @brief prints formatted text to stderr with newline at the end
     * @param fmt c-style format string
     * @param ...args format arguments
     * @note funciton adds 'Error: ' prefix to distinguish errors
     */
    template <class... Args>
    void printErr(const std::string& fmt, Args&&... args) {
        std::string fmterr = "Error: " + fmt + "\n";
        (void)fprintf(stderr, fmterr.c_str(), std::forward<Args>(args)...);
    }

    // OpenGL types because I dont want to include glad.h in header files
    
    typedef u32  GLbitfield;
    typedef u8   GLboolean;
    typedef i8   GLbyte;
    typedef f32  GLclampf;
    typedef u32  GLenum;
    typedef f32  GLfloat;
    typedef i32  GLint;
    typedef i16  GLshort;
    typedef i32  GLsizei;
    typedef u8   GLubyte;
    typedef u32  GLuint;
    typedef u16  GLushort;
    typedef void GLvoid;

}

