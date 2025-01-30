#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<int> AppendArrayToSeq(const std::vector<int>& s, const std::vector<int>& a) {
    // Preconditions
    REQUIRE(!a.empty()); // equivalent to a != null in Dafny

    std::vector<int> r = s; // Start with sequence s

    // Loop to append elements from array a to sequence r
    for (size_t i = 0; i < a.size(); ++i) {
        // Loop invariants
        assert(i <= a.size()); // 0 <= i <= a.Length
        assert(r.size() == s.size() + i); // |r| == |s| + i
        for (size_t j = 0; j < s.size(); ++j) {
            assert(r[j] == s[j]); // r[j] == s[j] for all j < |s|
        }
        for (size_t j = 0; j < i; ++j) {
            assert(r[s.size() + j] == a[j]); // r[|s| + j] == a[j] for all j < i
        }

        // Append current element from a to r
        r.push_back(a[i]);
    }

    // Postconditions
    ENSURE(r.size() == s.size() + a.size()); // |r| == |s| + a.Length
    for (size_t i = 0; i < s.size(); ++i) {
        ENSURE(r[i] == s[i]); // r[i] == s[i] for all i < |s|
    }
    for (size_t i = 0; i < a.size(); ++i) {
        ENSURE(r[s.size() + i] == a[i]); // r[|s| + i] == a[i] for all i < a.Length
    }

    return r;
}