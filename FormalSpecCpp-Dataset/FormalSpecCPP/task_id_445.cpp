#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<int> MultiplyElements(const std::vector<int>& a, const std::vector<int>& b) {
    // Preconditions
    REQUIRE(a.size() == b.size());

    std::vector<int> result;
    result.reserve(a.size()); // Reserve space to avoid reallocations

    // Loop to multiply elements
    for (size_t i = 0; i < a.size(); ++i) {
        // Loop invariants
        assert(result.size() == i);
        for (size_t k = 0; k < i; ++k) {
            assert(result[k] == a[k] * b[k]);
        }

        result.push_back(a[i] * b[i]);
    }

    // Postconditions
    ENSURE(result.size() == a.size());
    for (size_t i = 0; i < result.size(); ++i) {
        ENSURE(result[i] == a[i] * b[i]);
    }

    return result;
}