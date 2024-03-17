#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include <stdlib.h>

#include <glad/glad.h>
#include <glfw/glfw3.h>

#define SS_ASSERT(condition, errorText) if (!(condition)) {PrintErr(errorText); exit(1);}

namespace ssg {
    typedef int32_t i32;
    typedef int16_t i16;
    typedef int64_t i64;
    typedef int8_t  i8;

    typedef uint32_t u32;
    typedef uint16_t u16;
    typedef uint64_t u64;
    typedef uint8_t  u8;

    enum class Status {
        Success = 0,
        Error
    };

    template <class... Args>
    void Print(const std::string& fmt, Args&&... args) {
        (void)printf(fmt.c_str(), args...);
    }

    template <class... Args>
    void PrintErr(const std::string& fmt, Args&&... args) {
        std::string fmterr = "Error: " + fmt;
        (void)fprintf(stderr, fmterr.c_str(), args...);
    }
}

