#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<int> RemoveElement(const std::vector<int>& s, size_t k) {
    // Preconditions
    REQUIRE(k >= 0 && k < s.size());

    std::vector<int> v(s.size() - 1);
    size_t i = 0;

    // First loop: Copy elements from 0 to k-1
    while (i < k) {
        assert(i >= 0 && i <= k); // Loop invariant
        for (size_t j = 0; j < i; ++j) {
            assert(v[j] == s[j]); // Loop invariant
        }

        v[i] = s[i];
        i++;
    }

    // Assert to verify loop postcondition
    for (size_t j = 0; j < k; ++j) {
        assert(v[j] == s[j]);
    }

    // Second loop: Copy elements from k+1 to end
    while (i < v.size()) {
        assert(i >= k && i <= v.size()); // Loop invariant
        for (size_t j = k; j < i; ++j) {
            assert(v[j] == s[j + 1]); // Loop invariant
        }
        for (size_t j = 0; j < k; ++j) {
            assert(v[j] == s[j]); // Loop invariant
        }

        v[i] = s[i + 1];
        i++;
    }

    // Postconditions
    ENSURE(v.size() == s.size() - 1);
    for (size_t i = 0; i < k; ++i) {
        ENSURE(v[i] == s[i]);
    }
    for (size_t i = k; i < v.size(); ++i) {
        ENSURE(v[i] == s[i + 1]);
    }

    return v;
}