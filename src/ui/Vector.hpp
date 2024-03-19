#pragma once
#include "Core.hpp"
#include <imgui.h>

namespace ssgui {
    template <class T, u8 Components>
    class Vector {};

    template <class T>
    class Vector<T, 2> {
    public:
        Vector() : x(0), y(0) {}
        Vector(T x, T y) : x(x), y(y) {}
        Vector(const Vector<T, 2>& other) {
            x = other.x;
            y = other.y;
        }

        Vector<T, 2> operator+(const Vector<T, 2>& other) {return {x + other.x, y + other.y};}
        Vector<T, 2> operator-(const Vector<T, 2>& other) {return {x - other.x, y - other.y};}

        Vector<T, 2> operator*(const Vector<T, 2>& other) {return {x * other.x, y * other.y};}
        Vector<T, 2> operator/(const Vector<T, 2>& other) {return {x / other.x, y / other.y};}

        Vector<T, 2> operator+=(const Vector<T, 2>& other) {
            x += other.x;
            y += other.y;
            return *this;
        }

        Vector<T, 2> operator-=(const Vector<T, 2>& other) {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        Vector<T, 2> operator*=(const Vector<T, 2>& other) {
            x *= other.x;
            y *= other.y;
            return *this;
        }

        Vector<T, 2> operator/=(const Vector<T, 2>& other) {
            x /= other.x;
            y /= other.y;
            return *this;
        }

        f64 magnitude() const {
            return sqrt(pow(x, 2) + pow(y, 2));
        }

        ImVec2 asImgui() const {
            return {x, y};
        }

        union {T x, r;};
        union {T y, g;};
    };

    template <class T>
    class Vector<T, 3> {
    public:
        Vector() : x(0), y(0), z(0) {}
        Vector(T x, T y, T z) : x(x), y(y), z(z) {}
        Vector(const Vector<T, 2>& xy, T z) : x(xy.x), y(xy.y), z(z) {}
        Vector(const Vector<T, 3>& other) {
            x = other.x;
            y = other.y;
            z = other.z;
        }

        Vector<T, 3> operator+(const Vector<T, 3>& other) {return {x + other.x, y + other.y, z + other.z};}
        Vector<T, 3> operator-(const Vector<T, 3>& other) {return {x - other.x, y - other.y, z - other.z};}

        Vector<T, 3> operator*(const Vector<T, 3>& other) {return {x * other.x, y * other.y, z * other.z};}
        Vector<T, 3> operator/(const Vector<T, 3>& other) {return {x / other.x, y / other.y, z / other.z};}

        Vector<T, 3> operator+=(const Vector<T, 3>& other) {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }

        Vector<T, 3> operator-=(const Vector<T, 3>& other) {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            return *this;
        }

        Vector<T, 3> operator*=(const Vector<T, 3>& other) {
            x *= other.x;
            y *= other.y;
            z *= other.z;
            return *this;
        }

        Vector<T, 3> operator/=(const Vector<T, 3>& other) {
            x /= other.x;
            y /= other.y;
            z /= other.z;
            return *this;
        }

        f64 magnitude() const {
            return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
        }

        Vector<T, 2> xy() const {
            return {x, y};
        }

        union {T x, r;};
        union {T y, g;};
        union {T z, b;};
    };

    template <class T>
    class Vector<T, 4> {
    public:
        Vector() : x(0), y(0), z(0), w(0) {}
        Vector(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
        Vector(const Vector<T, 2>& xy, const Vector<T, 2>& zw) : x(xy.x), y(xy.y), z(zw.z), w(zw.w) {}
        Vector(const Vector<T, 3>& xyz, T w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}
        Vector(const Vector<T, 4>& other) {
            x = other.x;
            y = other.y;
            z = other.z;
            w = other.w;
        }

        Vector<T, 4> operator+(const Vector<T, 4>& other) {
            return {x + other.x, y + other.y, z + other.z, w + other.w};
        }
        Vector<T, 4> operator-(const Vector<T, 4>& other) {
            return {x - other.x, y - other.y, z - other.z, w + other.w};
        }

        Vector<T, 4> operator*(const Vector<T, 4>& other) {
            return {x * other.x, y * other.y, z * other.z, w * other.w};
        }
        Vector<T, 4> operator/(const Vector<T, 4>& other) {
            return {x / other.x, y / other.y, z / other.z, w / other.w};
        }

        Vector<T, 4> operator+=(const Vector<T, 4>& other) {
            x += other.x;
            y += other.y;
            z += other.z;
            w += other.w;
            return *this;
        }

        Vector<T, 4> operator-=(const Vector<T, 4>& other) {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            w -= other.w;
            return *this;
        }

        Vector<T, 4> operator*=(const Vector<T, 4>& other) {
            x *= other.x;
            y *= other.y;
            z *= other.z;
            w *= other.w;
            return *this;
        }

        Vector<T, 4> operator/=(const Vector<T, 4>& other) {
            x /= other.x;
            y /= other.y;
            z /= other.z;
            w /= other.w;
            return *this;
        }

        f64 magnitude() const {
            return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
        }

        Vector<T, 3> xyz() const {
            return {x, y, z};
        }

        ImVec4 asImgui() const {
            return {x, y, z, w};
        }

        union {T x, r;};
        union {T y, g;};
        union {T z, b;};
        union {T w, a;};
    };

    typedef Vector<f32, 2> Vector2;
    typedef Vector<f32, 3> Vector3;
    typedef Vector<f32, 4> Vector4;

    typedef Vector<f64, 2> Vector2d;
    typedef Vector<f64, 3> Vector3d;
    typedef Vector<f64, 4> Vector4d;

    typedef Vector<i32, 2> Vector2i;
    typedef Vector<i32, 3> Vector3i;
    typedef Vector<i32, 4> Vector4i;

    typedef Vector<u32, 2> Vector2u;
    typedef Vector<u32, 3> Vector3u;
    typedef Vector<u32, 4> Vector4u;
}
