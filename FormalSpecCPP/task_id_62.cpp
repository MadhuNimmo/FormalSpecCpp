#include <cassert>
#include <vector>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int FindSmallest(const std::vector<int>& s) {
    // Precondition: the array must not be empty
    REQUIRE(s.size() > 0);

    int min = s[0];

    // Loop through the array starting from the second element
    for (size_t i = 1; i < s.size(); ++i) {
        // Loop invariants
        assert(i >= 0 && i <= s.size()); // Ensures i is within valid range
        for (size_t k = 0; k < i; ++k) {
            assert(min <= s[k]); // Ensures min is the smallest in the checked part
        }
        bool exists = false;
        for (size_t k = 0; k < i; ++k) {
            if (min == s[k]) {
                exists = true;
                break;
            }
        }
        assert(exists); // Ensures there is at least one element equal to min in the checked part

        // Update min if a smaller element is found
        if (s[i] < min) {
            min = s[i];
        }
    }

    // Postconditions
    for (size_t i = 0; i < s.size(); ++i) {
        ENSURE(min <= s[i]); // Ensures min is less than or equal to all elements in the array
    }
    bool exists = false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (min == s[i]) {
            exists = true;
            break;
        }
    }
    ENSURE(exists); // Ensures there is at least one element equal to min in the array

    return min;
}