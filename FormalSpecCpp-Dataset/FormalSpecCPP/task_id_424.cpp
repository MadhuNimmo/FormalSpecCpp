#include <vector>
#include <string>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<char> ExtractRearChars(const std::vector<std::string>& l) {
    // Precondition: All strings in l must be non-empty.
    for (const auto& s : l) {
        REQUIRE(!s.empty());
    }

    std::vector<char> rearChars;
    rearChars.reserve(l.size()); // Reserve space to avoid reallocations

    // Loop invariant setup
    size_t i = 0;
    while (i < l.size()) {
        // Loop invariant: rearChars.size() == i
        assert(rearChars.size() == i);
        // Loop invariant: All characters in rearChars are the last characters of the corresponding strings in l
        for (size_t k = 0; k < i; ++k) {
            assert(rearChars[k] == l[k][l[k].size() - 1]);
        }

        // Main operation: Append the last character of the current string in l to rearChars
        rearChars.push_back(l[i][l[i].size() - 1]);
        ++i;
    }

    // Postcondition: The size of rearChars must be equal to the size of l
    ENSURE(rearChars.size() == l.size());
    // Postcondition: Each element in rearChars must be the last character of the corresponding string in l
    for (size_t j = 0; j < l.size(); ++j) {
        ENSURE(rearChars[j] == l[j][l[j].size() - 1]);
    }

    return rearChars;
}