#include <cmath>

#include "Math.hpp"

namespace SAT {

Vec2::Vec2() {}

Vec2::Vec2(float x, float y) : x(x), y(y) {}

Vec2 Vec2::operator+(const Vec2 &vec) const {
    return Vec2(x + vec.x, y + vec.y);
}

Vec2 Vec2::operator-(const Vec2 &vec) const {
    return Vec2(x - vec.x, y - vec.y);
}

Vec2 Vec2::operator/(float value) const { return Vec2(x / value, y / value); }

Vec2 Vec2::operator*(float value) const { return Vec2(x * value, y * value); }

float Vec2::magnitude() const { return std::sqrt(x * x + y * y); }

Vec2 Vec2::unit() const { return Vec2(x, y) / magnitude(); }

Vec2 Vec2::normal() const { return Vec2(y, -x); }

float Vec2::dot(const Vec2 &vec) const { return x * vec.x + y * vec.y; }

} // namespace SAT
