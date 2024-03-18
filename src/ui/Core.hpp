#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <stdlib.h>

#define SS_ASSERT(condition, errorText) if (!(condition)) {PrintErr(errorText); exit(Status_Error);}

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

    enum Status {
        Status_Success = 0,
        Status_Error = 1,
    };

    template <class... Args>
    void Print(const std::string& fmt, Args&&... args) {
        std::string fmtout = fmt + "\n";
        (void)printf(fmtout.c_str(), args...);
    }

    template <class... Args>
    void PrintErr(const std::string& fmt, Args&&... args) {
        std::string fmterr = "Error: " + fmt + "\n";
        (void)fprintf(stderr, fmterr.c_str(), args...);
    }
}

