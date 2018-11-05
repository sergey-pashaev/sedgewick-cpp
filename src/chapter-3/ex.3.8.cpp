// ex.3.8

// en: Add a function to the point data type (Programs 3.3 and 3.4)
// that determines whether or not three points are collinear, to
// within a numerical tolerance of 10^–4. Assume that the points are
// all in the unit square.

// ru: Добавьте к типу данных Point функцию, которая определяет, лежат
// ли три точки на одной прямой, с допуском 10^-4. Считайте, что все
// точки находятся в единичном квадрате.

#include <catch.hpp>

#include "point.h"

TEST_CASE("is_collinear") {
    const float epsilon = 1.e-4;

    // positive
    REQUIRE(is_collinear({0.0, 0.0}, {0.0, 0.1}, {0.0, 0.2}, epsilon));
    REQUIRE(is_collinear({0.1, 0.1}, {0.2, 0.2}, {0.3, 0.3}, epsilon));

    // negative
    REQUIRE(!is_collinear({0.3, 0.1}, {0.2, 0.2}, {0.3, 0.3}, epsilon));
    REQUIRE(!is_collinear({0.3, 0.1}, {1.0, 0.2}, {0.6, 0.3}, epsilon));
}
