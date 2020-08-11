#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CollisionDetection.hpp"

using namespace SAT;

SCENARIO("Convex shapes intersect") {
    CollisionDetection collision;

    GIVEN("first shape is axis aligned triangle") {
        CollisionShape shape1({Vec2(0, 0), Vec2(1, 0), Vec2(1, 1)});

        WHEN("second shape is axis aligned triangle") {
            CollisionShape shape2({Vec2(0, 1), Vec2(1, 0), Vec2(1, 1)});

            THEN("collision detected") {
                bool collisionResult = collision.detect(shape1, shape2);
                REQUIRE(collisionResult);
            }
        }

        WHEN("second shape is axis aligned rectangle") {
            CollisionShape shape2(
                {Vec2(0, 0), Vec2(1, 0), Vec2(1, 1), Vec2(0, 1)});

            THEN("collision detected") {
                bool collisionResult = collision.detect(shape1, shape2);
                REQUIRE(collisionResult);
            }
        }

        WHEN("second shape is oriented triangle") {
            CollisionShape shape2({Vec2(0, 1), Vec2(0.75, 0), Vec2(1, 0.75)});

            THEN("collision detected") {
                bool collisionResult = collision.detect(shape1, shape2);
                REQUIRE(collisionResult);
            }
        }

        WHEN("second shape is oriented rectangle") {
            CollisionShape shape2(
                {Vec2(0.25, 0), Vec2(1, 0.25), Vec2(0.75, 1), Vec2(0, 0.75)});

            THEN("collision detected") {
                bool collisionResult = collision.detect(shape1, shape2);
                REQUIRE(collisionResult);
            }
        }
    }

    GIVEN("first shape is axis aligned rectangle") {
        CollisionShape shape1(
            {Vec2(0.25, 0), Vec2(0.75, 0), Vec2(0.75, 1), Vec2(0.25, 1)});

        WHEN("second shape is axis aligned triangle") {
            CollisionShape shape2({Vec2(0, 1), Vec2(1, 0), Vec2(1, 1)});

            THEN("collision detected") {
                bool collisionResult = collision.detect(shape1, shape2);
                REQUIRE(collisionResult);
            }
        }

        WHEN("second shape is axis aligned rectangle") {
            CollisionShape shape2(
                {Vec2(0, 0.25), Vec2(1, 0.25), Vec2(1, 0.75), Vec2(0, 0.75)});

            THEN("collision detected") {
                bool collisionResult = collision.detect(shape1, shape2);
                REQUIRE(collisionResult);
            }
        }

        WHEN("second shape is oriented triangle") {
            CollisionShape shape2({Vec2(0, 1), Vec2(0.75, 0), Vec2(1, 0.75)});

            THEN("collision detected") {
                bool collisionResult = collision.detect(shape1, shape2);
                REQUIRE(collisionResult);
            }
        }

        WHEN("second shape is oriented rectangle") {
            CollisionShape shape2(
                {Vec2(0.25, 0), Vec2(1, 0.25), Vec2(0.75, 1), Vec2(0, 0.75)});

            THEN("collision detected") {
                bool collisionResult = collision.detect(shape1, shape2);
                REQUIRE(collisionResult);
            }
        }
    }
}

SCENARIO("Convex shapes dont intersect") {
    CollisionDetection collision;

    GIVEN("first shape is oriented triangle") {
        CollisionShape shape1({Vec2(0, 0), Vec2(0.3, 0.8), Vec2(0.4, 0.5)});

        WHEN("second shape is axis aligned triangle") {
            CollisionShape shape2({Vec2(0.5, 0), Vec2(0.5, 1), Vec2(1, 0)});

            THEN("collision not detected") {
                bool collisionResult = collision.detect(shape1, shape2);
                REQUIRE(!collisionResult);
            }
        }

        WHEN("second shape is axis aligned rectangle") {
            CollisionShape shape2(
                {Vec2(0.3, 0), Vec2(0.3, 0.2), Vec2(0.4, 0.2), Vec2(0.4, 0)});

            THEN("collision not detected") {
                bool collisionResult = collision.detect(shape1, shape2);
                REQUIRE(!collisionResult);
            }
        }

        WHEN("second shape is oriented triangle") {
            CollisionShape shape2(
                {Vec2(0.2, 0), Vec2(0.5, 0.3), Vec2(0.6, 0.2)});

            THEN("collision not detected") {
                bool collisionResult = collision.detect(shape1, shape2);
                REQUIRE(!collisionResult);
            }
        }

        WHEN("second shape is oriented rectangle") {
            CollisionShape shape2({Vec2(0.5, 0.7), Vec2(0.7, 0.8),
                                   Vec2(0.8, 0.6), Vec2(0.6, 0.5)});

            THEN("collision not detected") {
                bool collisionResult = collision.detect(shape1, shape2);
                REQUIRE(!collisionResult);
            }
        }
    }

    GIVEN("first shape is oriented rectangle") {
        CollisionShape shape1(
            {Vec2(0.1, 0.7), Vec2(0.3, 0.8), Vec2(0.4, 0.5), Vec2(0.2, 0.4)});

        WHEN("second shape is axis aligned triangle") {
            CollisionShape shape2({Vec2(0.5, 0), Vec2(0.5, 1), Vec2(1, 0)});

            THEN("collision not detected") {
                bool collisionResult = collision.detect(shape1, shape2);
                REQUIRE(!collisionResult);
            }
        }

        WHEN("second shape is axis aligned rectangle") {
            CollisionShape shape2(
                {Vec2(0.3, 0), Vec2(0.3, 0.2), Vec2(0.4, 0.2), Vec2(0.4, 0)});

            THEN("collision not detected") {
                bool collisionResult = collision.detect(shape1, shape2);
                REQUIRE(!collisionResult);
            }
        }

        WHEN("second shape is oriented triangle") {
            CollisionShape shape2(
                {Vec2(0.2, 0), Vec2(0.5, 0.3), Vec2(0.6, 0.2)});

            THEN("collision not detected") {
                bool collisionResult = collision.detect(shape1, shape2);
                REQUIRE(!collisionResult);
            }
        }

        WHEN("second shape is oriented rectangle") {
            CollisionShape shape2({Vec2(0.5, 0.7), Vec2(0.7, 0.8),
                                   Vec2(0.8, 0.6), Vec2(0.6, 0.5)});

            THEN("collision not detected") {
                bool collisionResult = collision.detect(shape1, shape2);
                REQUIRE(!collisionResult);
            }
        }
    }
}