#include <vector>
#include <cassert>
#include <algorithm>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int SmallestListLength(const std::vector<std::vector<int>>& s) {
    // Precondition: s must not be empty
    REQUIRE(!s.empty());

    // Initialize v to the length of the first inner vector
    size_t v = s[0].size();

    // Loop through each vector in s starting from the second one
    for (size_t i = 1; i < s.size(); ++i) {
        // Loop invariants
        assert(i <= s.size()); // Ensures i does not exceed the number of vectors in s
        for (size_t k = 0; k < i; ++k) {
            assert(v <= s[k].size()); // Ensures v is less than or equal to all checked lengths
        }
        bool exists = false;
        for (size_t k = 0; k < i; ++k) {
            if (v == s[k].size()) {
                exists = true;
                break;
            }
        }
        assert(exists); // Ensures there is at least one vector with length equal to v

        // Update v if the current vector's size is smaller
        if (s[i].size() < v) {
            v = s[i].size();
        }
    }

    // Postconditions
    for (const auto& vec : s) {
        ENSURE(v <= vec.size()); // Ensures v is less than or equal to all vector sizes in s
    }
    bool exists_final = std::any_of(s.begin(), s.end(), [v](const std::vector<int>& vec) { return vec.size() == v; });
    ENSURE(exists_final); // Ensures there is at least one vector with length exactly v

    return static_cast<int>(v); // Return the smallest length found
}