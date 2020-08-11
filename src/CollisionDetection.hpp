#pragma once

#include "CollisionShape.hpp"

namespace SAT {

class CollisionDetection {
  public:
    bool detect(const CollisionShape &shape1,
                const CollisionShape &shape2) const;

  private:
    std::vector<Vec2> getAxises(const std::vector<Vec2> &corners) const;
};

} // namespace SAT
