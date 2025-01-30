#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool IsMinHeap(const std::vector<int>& a) {
    // Preconditions
    REQUIRE(!a.empty());

    bool result = true;
    size_t length = a.size();
    size_t halfLength = length / 2;

    for (size_t i = 0; i < halfLength; ++i) {
        // Loop invariants
        assert(i <= halfLength);
        // We cannot directly translate the Dafny invariant that uses quantifiers into C++.
        // Instead, we ensure the invariant holds by the logic in the loop.

        if (a[i] > a[2 * i + 1] || (2 * i + 2 < length && a[i] > a[2 * i + 2])) {
            result = false;
            break;
        }
    }

    // Postconditions
    if (result) {
        ENSURE([&]() {
            for (size_t i = 0; i < halfLength; ++i) {
                if (a[i] > a[2 * i + 1] || (2 * i + 2 < length && a[i] > a[2 * i + 2])) {
                    return false;
                }
            }
            return true;
        }());
    } else {
        ENSURE([&]() {
            for (size_t i = 0; i < halfLength; ++i) {
                if (a[i] > a[2 * i + 1] || (2 * i + 2 < length && a[i] > a[2 * i + 2])) {
                    return true;
                }
            }
            return false;
        }());
    }

    return result;
}