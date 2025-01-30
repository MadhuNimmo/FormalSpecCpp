#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<double> ElementWiseDivision(const std::vector<int>& a, const std::vector<int>& b) {
    // Preconditions
    REQUIRE(a.size() == b.size());
    for (size_t i = 0; i < b.size(); ++i) {
        REQUIRE(b[i] != 0);
    }

    std::vector<double> result;
    result.reserve(a.size());

    // Loop to perform element-wise division
    for (size_t i = 0; i < a.size(); ++i) {
        // Loop invariants
        assert(i <= a.size());
        assert(result.size() == i);
        for (size_t k = 0; k < i; ++k) {
            assert(result[k] == a[k] / b[k]);
        }

        result.push_back(a[i] / b[i]);
    }

    // Postconditions
    ENSURE(result.size() == a.size());
    for (size_t i = 0; i < result.size(); ++i) {
        ENSURE(result[i] == a[i] / b[i]);
    }

    return result;
}