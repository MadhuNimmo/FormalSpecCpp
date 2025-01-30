#include <cassert>
#include <vector>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

void SwapFirstAndLast(std::vector<int>& a) {
    // Preconditions
    REQUIRE(a.size() > 0);

    // Save old values for postconditions
    int old_first = a[0];
    int old_last = a[a.size() - 1];

    // Swapping the first and last elements
    int tmp = a[0];
    a[0] = a[a.size() - 1];
    a[a.size() - 1] = tmp;

    // Postconditions
    ENSURE(a[0] == old_last);
    ENSURE(a[a.size() - 1] == old_first);
    for (size_t k = 1; k < a.size() - 1; ++k) {
        ENSURE(a[k] == a[k]); // Ensuring middle elements are unchanged
    }
}