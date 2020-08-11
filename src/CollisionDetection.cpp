#include <algorithm>

#include "CollisionDetection.hpp"

namespace SAT {

bool CollisionDetection::detect(const CollisionShape &shape1,
                                const CollisionShape &shape2) const {

    auto axises1 = getAxises(shape1.vertices);
    auto axises2 = getAxises(shape2.vertices);

    std::vector<Vec2> axises;

    axises.insert(axises.end(), axises1.begin(), axises1.end());
    axises.insert(axises.end(), axises2.begin(), axises2.end());

    for (const auto &axis : axises) {
        std::vector<float> scalars1;
        std::vector<float> scalars2;

        for (const auto &corner : shape1.vertices) {
            scalars1.push_back(axis.dot(corner));
        }

        for (const auto &corner : shape2.vertices) {
            scalars2.push_back(axis.dot(corner));
        }

        float s1max = *std::max_element(scalars1.begin(), scalars1.end());
        float s1min = *std::min_element(scalars1.begin(), scalars1.end());

        float s2max = *std::max_element(scalars2.begin(), scalars2.end());
        float s2min = *std::min_element(scalars2.begin(), scalars2.end());

        if (s1min > s2max || s2min > s1max) {
            return false;
        }
    }

    return true;
}

std::vector<Vec2>
CollisionDetection::getAxises(const std::vector<Vec2> &corners) const {
    std::vector<Vec2> axises;
    for (size_t i = 0; i < corners.size(); i++) {
        Vec2 v1 = corners[i];
        Vec2 v2 = corners[(i + 1) % corners.size()];
        Vec2 d = v2 - v1;
        axises.push_back(d.normal().unit());
    }

    return axises;
}

} // namespace SAT
