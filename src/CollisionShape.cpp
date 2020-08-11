#include "CollisionShape.hpp"

namespace SAT {

CollisionShape::CollisionShape() {}

CollisionShape::CollisionShape(const std::vector<Vec2> &vertices)
    : vertices(vertices) {}

} // namespace SAT
