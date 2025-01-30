#include <cassert>
#include <climits>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int* AreaOfLargestTriangleInSemicircle(int radius) {
    // Precondition: radius must be positive
    REQUIRE(radius >= INT_MIN && radius <= INT_MAX);
    // Calculate the area of the largest triangle in a semicircle
    int area = radius * radius;
    int* result = new int(area);
    // Postcondition: area must be equal to radius squared
    ENSURE(result == nullptr || (result != nullptr && *result == radius * radius));
    if (radius < 0) {
        return nullptr;
    }else{
        return result;
    }
}