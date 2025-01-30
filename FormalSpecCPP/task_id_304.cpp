#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int ElementAtIndexAfterRotation(const std::vector<int>& l, unsigned int n, size_t index) {
    // Preconditions
    REQUIRE(n >= 0);
    REQUIRE(index < l.size());

    // Calculation
    n = n % l.size();
    size_t adjusted_index = (index + l.size() - n) % l.size();
    int element = l[adjusted_index];

    // Postcondition
    ENSURE(element == l[(index - n + l.size()) % l.size()]);

    return element;
}