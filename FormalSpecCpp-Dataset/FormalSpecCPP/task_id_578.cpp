#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<int> Interleave(const std::vector<int>& s1, const std::vector<int>& s2, const std::vector<int>& s3) {
    // Preconditions
    REQUIRE(s1.size() == s2.size() && s2.size() == s3.size());

    std::vector<int> r;
    r.reserve(3 * s1.size());

    // Loop invariant setup
    for (size_t i = 0; i < s1.size(); ++i) {
        // Loop invariants
        assert(r.size() == 3 * i);
        for (size_t k = 0; k < i; ++k) {
            assert(r[3 * k] == s1[k] && r[3 * k + 1] == s2[k] && r[3 * k + 2] == s3[k]);
        }

        // Main operation
        r.push_back(s1[i]);
        r.push_back(s2[i]);
        r.push_back(s3[i]);
    }

    // Postconditions
    ENSURE(r.size() == 3 * s1.size());
    for (size_t i = 0; i < s1.size(); ++i) {
        ENSURE(r[3 * i] == s1[i] && r[3 * i + 1] == s2[i] && r[3 * i + 2] == s3[i]);
    }

    return r;
}