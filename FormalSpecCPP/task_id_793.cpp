#include <cassert>
#include <vector>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int LastPosition(const std::vector<int>& arr, int elem) {
    // Preconditions
    REQUIRE(arr.size() > 0);

    int pos = -1;
    for (size_t i = 0; i < arr.size(); ++i) {
        // Loop invariants
        assert(0 <= i && i <= arr.size());

        // Update pos when the element matches
        if (arr[i] == elem) {
            pos = static_cast<int>(i);
        }
    }

    // Postconditions
    ENSURE(pos == -1 || (0 <= pos && static_cast<size_t>(pos) < arr.size() && arr[pos] == elem));

    return pos;
}
