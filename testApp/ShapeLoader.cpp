#include "ShapeLoader.hpp"
#include "Math.hpp"

#include <fstream>

std::vector<SAT::CollisionShape>
ShapeLoader::load(const std::string &path) const {
    std::ifstream in(path, std::ios::in | std::ios::binary);
    std::stringstream dto;
    std::string line;

    std::vector<SAT::CollisionShape> shapes;

    while (std::getline(in, line)) {
        if (line.empty()) {
            auto shape = getShape(dto);
            shapes.push_back(shape);
            dto.str(std::string());
        } else {
            dto << line << std::endl;
        }
    }

    if (!dto.eof()) {
        auto shape = getShape(dto);
        shapes.push_back(shape);
    }

    in.close();

    return shapes;
}

SAT::CollisionShape ShapeLoader::getShape(std::stringstream &in) const {
    std::vector<SAT::Vec2> vertices;

    while (!in.eof()) {
        float x, y;
        in >> x >> y;
        vertices.emplace_back(x, y);
        in >> std::ws;
    }

    return SAT::CollisionShape(vertices);
}
