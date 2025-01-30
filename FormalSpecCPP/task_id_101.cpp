#include <cassert>
#include <vector>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

int KthElement(const std::vector<int>& arr, size_t k) {
    // Preconditions
    REQUIRE(k >= 1 && k <= arr.size());

    int result = arr[k - 1];

    // Postconditions
    ENSURE(result == arr[k - 1]);

    return result;
}