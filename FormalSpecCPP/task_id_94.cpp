#include <cassert>
#include <vector>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int MinSecondValueFirst(const std::vector<std::vector<int>>& s) {
    // Preconditions
    REQUIRE(s.size() > 0);
    for (const auto& seq : s) {
        REQUIRE(seq.size() >= 2);
    }

    // Initial assumption based on preconditions
    size_t minSecondIndex = 0;

    // Loop through the array of sequences
    for (size_t i = 1; i < s.size(); ++i) {
        // Loop invariant: minSecondIndex is valid and has the minimum second element seen so far
        assert(0 <= minSecondIndex && minSecondIndex < i);
        for (size_t j = 0; j < i; ++j) {
            assert(s[minSecondIndex][1] <= s[j][1]);
        }

        // Update minSecondIndex if a new smaller second element is found
        if (s[i][1] < s[minSecondIndex][1]) {
            minSecondIndex = i;
        }
    }

    // Postcondition: the first element of the sequence with the smallest second element
    int firstOfMinSecond = s[minSecondIndex][0];
    ENSURE([&]() {
        for (size_t j = 0; j < s.size(); ++j) {
            if (s[minSecondIndex][1] > s[j][1]) return false;
        }
        return true;
    }());

    return firstOfMinSecond;
}