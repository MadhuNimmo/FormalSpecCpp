#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<int> SubtractSequences(const std::vector<int>& a, const std::vector<int>& b) {
    // Preconditions
    REQUIRE(a.size() == b.size());

    std::vector<int> result;
    result.reserve(a.size()); // Reserve space to avoid reallocations

    // Loop to subtract elements
    for (size_t i = 0; i < a.size(); ++i) {
        // Loop invariants
        assert(i <= a.size()); // Ensures i does not exceed the size of a
        assert(result.size() == i); // Ensures the size of result is equal to i

        // Subtract and add to result
        result.push_back(a[i] - b[i]);
    }

    // Postconditions
    ENSURE(result.size() == a.size());
    for (size_t i = 0; i < result.size(); ++i) {
        ENSURE(result[i] == a[i] - b[i]);
    }

    return result;
}