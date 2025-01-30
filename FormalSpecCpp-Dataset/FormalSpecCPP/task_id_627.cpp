#include <cassert>
#include <vector>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int SmallestMissingNumber(const std::vector<int>& s) {
    // Preconditions
    for (size_t i = 0; i < s.size(); ++i) {
        for (size_t j = i + 1; j < s.size(); ++j) {
            REQUIRE(s[i] <= s[j]); // s is sorted
        }
        REQUIRE(s[i] >= 0); // all elements are non-negative
    }

    int v = 0;
    size_t i = 0;
    for (; i < s.size(); ++i) {
        // Loop invariants
        assert(0 <= i && i <= s.size()); // i is within bounds
        assert(0 <= v && v <= static_cast<int>(i)); // v is within bounds and less than or equal to i
        bool v_not_in_s = true;
        for (size_t j = 0; j < i; ++j) {
            if (s[j] == v) {
                v_not_in_s = false;
                break;
            }
        }
        assert(v_not_in_s); // v is not in the subsequence s[0..i)

        if (s[i] > v) {
            break;
        } else if (s[i] == v) {
            v += 1;
        }
    }

    // Postconditions
    ENSURE(0 <= v); // v is non-negative
    bool v_not_in_s_final = true;
    for (size_t j = 0; j < s.size(); ++j) {
        if (s[j] == v) {
            v_not_in_s_final = false;
            break;
        }
    }
    ENSURE(v_not_in_s_final); // v is not in the sequence s

    for (int k = 0; k < v; ++k) {
        bool k_in_s = false;
        for (size_t j = 0; j < s.size(); ++j) {
            if (s[j] == k) {
                k_in_s = true;
                break;
            }
        }
        ENSURE(k_in_s); // every k < v is in s
    }

    return v;
}