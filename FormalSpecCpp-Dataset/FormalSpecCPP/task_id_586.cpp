#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<int> SplitAndAppend(const std::vector<int>& l, size_t n) {
    // Preconditions
    REQUIRE(n >= 0 && n < l.size());

    std::vector<int> firstPart(l.begin(), l.begin() + n);
    std::vector<int> secondPart(l.begin() + n, l.end());
    std::vector<int> r(secondPart.begin(), secondPart.end());
    r.insert(r.end(), firstPart.begin(), firstPart.end());

    // Postconditions
    ENSURE(r.size() == l.size());
    for (size_t i = 0; i < l.size(); ++i) {
        ENSURE(r[i] == l[(i + n) % l.size()]);
    }

    return r;
}