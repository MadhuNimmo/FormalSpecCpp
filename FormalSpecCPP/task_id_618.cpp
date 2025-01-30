#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<double> ElementWiseDivide(const std::vector<int>& a, const std::vector<int>& b) {
    // Preconditions
    REQUIRE(a.size() == b.size());
    for (size_t i = 0; i < b.size(); ++i) {
        REQUIRE(b[i] != 0);
    }

    std::vector<double> result;
    result.reserve(a.size());

    // Loop invariant setup and processing
    for (size_t i = 0; i < a.size(); ++i) {
        // Loop invariants
        assert(i <= a.size()); // invariant 0 <= i <= |a|
        assert(result.size() == i); // invariant |result| == i
        for (size_t k = 0; k < i; ++k) {
            assert(result[k] == static_cast<double>(a[k]) / b[k]); // invariant result[k] == a[k] / b[k]
        }

        result.push_back(static_cast<double>(a[i]) / b[i]);
    }

    // Postconditions
    ENSURE(result.size() == a.size());
    for (size_t i = 0; i < result.size(); ++i) {
        ENSURE(result[i] == static_cast<double>(a[i]) / b[i]);
    }

    return result;
}