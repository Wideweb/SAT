#pragma once

namespace SAT {

struct Vec2 {
    float x = 0;
    float y = 0;

    Vec2();
    Vec2(float x, float y);

    Vec2 operator+(const Vec2 &vec) const;
    Vec2 operator-(const Vec2 &vec) const;
    Vec2 operator/(float value) const;
    Vec2 operator*(float value) const;

    float magnitude() const;
    Vec2 unit() const;
    Vec2 normal() const;
    float dot(const Vec2 &vec) const;
};

} // namespace SAT
