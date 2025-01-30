#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<int> ElementWiseSubtraction(const std::vector<int>& a, const std::vector<int>& b) {
    // Preconditions
    REQUIRE(!a.empty() && !b.empty());
    REQUIRE(a.size() == b.size());

    std::vector<int> result(a.size());

    // Loop to perform element-wise subtraction
    for (size_t i = 0; i < a.size(); ++i) {
        // Loop invariants
        assert(i <= a.size()); // Ensures loop does not exceed bounds
        assert(result.size() == a.size()); // Ensures result vector is correctly sized

        result[i] = a[i] - b[i];
    }

    // Postconditions
    ENSURE(!result.empty());
    ENSURE(result.size() == a.size());
    for (size_t i = 0; i < result.size(); ++i) {
        ENSURE(result[i] == a[i] - b[i]); // Ensures each element is correctly subtracted
    }

    return result;
}