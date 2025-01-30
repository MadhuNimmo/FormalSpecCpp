#include <vector>
#include <cassert>
#include <algorithm>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<int> MinLengthSublist(const std::vector<std::vector<int>>& s) {
    // Preconditions
    REQUIRE(s.size() > 0);

    std::vector<int> minSublist = s[0];
    size_t i;

    // Loop invariant setup
    for (i = 1; i < s.size(); ++i) {
        // Loop invariants
        assert(i >= 0 && i <= s.size());  // invariant 0 <= i <= |s|
        assert(std::find(s.begin(), s.begin() + i, minSublist) != s.begin() + i);  // invariant minSublist in s[..i]
        for (size_t j = 0; j < i; ++j) {
            assert(minSublist.size() <= s[j].size());  // invariant |minSublist| <= |sublist|
        }

        if (s[i].size() < minSublist.size()) {
            minSublist = s[i];
        }
    }

    // Postconditions
    ENSURE(std::find(s.begin(), s.end(), minSublist) != s.end());  // ensures minSublist in s
    for (const auto& sublist : s) {
        ENSURE(minSublist.size() <= sublist.size());  // ensures |minSublist| <= |sublist|
    }

    return minSublist;
}