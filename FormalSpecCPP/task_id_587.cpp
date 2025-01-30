#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<int> ArrayToSeq(const std::vector<int>& a) {
    // Preconditions
    REQUIRE(!a.empty());

    std::vector<int> s;
    size_t length = a.size();

    // Loop to convert array to sequence
    for (size_t i = 0; i < length; ++i) {
        // Loop invariants
        assert(i <= length); // invariant 0 <= i <= a.Length
        assert(s.size() == i); // invariant |s| == i
        for (size_t j = 0; j < i; ++j) {
            assert(s[j] == a[j]); // invariant forall j :: 0 <= j < i ==> s[j] == a[j]
        }

        s.push_back(a[i]);
    }

    // Postconditions
    ENSURE(s.size() == length); // ensures |s| == a.Length
    for (size_t i = 0; i < length; ++i) {
        ENSURE(s[i] == a[i]); // ensures forall i :: 0 <= i < a.Length ==> s[i] == a[i]
    }

    return s;
}