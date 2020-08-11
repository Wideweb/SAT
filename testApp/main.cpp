#include "CollisionDetection.hpp"

#include "ShapeLoader.hpp"
#include <assert.h>
#include <iostream>

int main() {
    ShapeLoader loader;
    auto shapes = loader.load("./assets/shapes.txt");

    assert(shapes.size() == 2);

    SAT::CollisionDetection collision;
    bool result = collision.detect(shapes[0], shapes[1]);

    std::cout << (result ? "YES" : "NO") << std::endl;
    int wait;
    std::cin >> wait;
}
