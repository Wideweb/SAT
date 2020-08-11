#pragma once

#include <vector>

#include "Math.hpp"

namespace SAT {

struct CollisionShape {
    std::vector<Vec2> vertices;

    CollisionShape();
    CollisionShape(const std::vector<Vec2> &vertices);
};

} // namespace SAT
