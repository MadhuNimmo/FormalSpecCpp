#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<int> ElementWiseModulo(const std::vector<int>& a, const std::vector<int>& b) {
    // Preconditions
    REQUIRE(!a.empty() && !b.empty());
    REQUIRE(a.size() == b.size());
    for (size_t i = 0; i < b.size(); ++i) {
        REQUIRE(b[i] != 0);
    }

    std::vector<int> result(a.size());

    // Loop to calculate element-wise modulo
    for (size_t i = 0; i < a.size(); ++i) {
        // Loop invariants
        assert(i <= a.size()); // Ensures loop does not exceed array bounds
        assert(result.size() == a.size()); // Ensures result array is correctly sized

        result[i] = a[i] % b[i];
    }

    // Postconditions
    ENSURE(!result.empty());
    ENSURE(result.size() == a.size());
    for (size_t i = 0; i < result.size(); ++i) {
        ENSURE(result[i] == a[i] % b[i]);
    }

    return result;
}