#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<int> AddLists(const std::vector<int>& a, const std::vector<int>& b) {
    // Preconditions
    REQUIRE(a.size() == b.size());

    std::vector<int> result;
    result.reserve(a.size()); // Reserve space to avoid reallocations

    // Loop invariant setup
    for (size_t i = 0; i < a.size(); ++i) {
        // Loop invariants
        assert(i <= a.size()); // invariant 0 <= i <= |a|
        assert(result.size() == i); // invariant |result| == i
        for (size_t k = 0; k < i; ++k) {
            assert(result[k] == a[k] + b[k]); // invariant forall k :: 0 <= k < i ==> result[k] == a[k] + b[k]
        }

        // Main operation
        result.push_back(a[i] + b[i]);
    }

    // Postconditions
    ENSURE(result.size() == a.size()); // ensures |result| == |a|
    for (size_t i = 0; i < result.size(); ++i) {
        ENSURE(result[i] == a[i] + b[i]); // ensures forall i :: 0 <= i < |result| ==> result[i] == a[i] + b[i]
    }

    return result;
}