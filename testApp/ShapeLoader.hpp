#pragma once

#include "CollisionShape.hpp"
#include <sstream>
#include <string>
#include <vector>

class ShapeLoader {
  public:
    std::vector<SAT::CollisionShape> load(const std::string &path) const;

  private:
    SAT::CollisionShape getShape(std::stringstream &in) const;
};
