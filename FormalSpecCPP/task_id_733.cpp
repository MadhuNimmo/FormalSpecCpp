#include <cassert>
#include <vector>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int FindFirstOccurrence(const std::vector<int>& arr, int target) {
    // Preconditions
    REQUIRE(!arr.empty());

    int index = -1;
    for (size_t i = 0; i < arr.size(); ++i) {
        // Loop invariants
        assert(0 <= i && i <= arr.size()); // bounds check
        if (index == -1) {
            for (size_t k = 0; k < i; ++k) {
                assert(arr[k] != target); // target not found in the previous elements
            }
        }
        if (0 <= index && index < static_cast<int>(i)) {
            assert(arr[index] == target); // target found at index
        }

        if (arr[i] == target) {
            index = static_cast<int>(i);
            break;
        }
        if (arr[i] > target) {
            break;
        }
    }

    // Postconditions
    if (0 <= index && index < static_cast<int>(arr.size())) {
        ENSURE(arr[index] == target); // target found at index
    }
    if (index == -1) {
        for (size_t i = 0; i < arr.size(); ++i) {
            ENSURE(arr[i] != target); // target not found in the array
        }
    }

    return index;
}