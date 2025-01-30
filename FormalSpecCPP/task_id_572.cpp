#include <vector>
#include <cassert>
#include <algorithm>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<int> RemoveDuplicates(const std::vector<int>& a) {
    // Preconditions
    REQUIRE(!a.empty());

    std::vector<int> result;
    size_t length = a.size();

    // Processing each element in the array
    for (size_t i = 0; i < length; ++i) {
        // Loop invariants
        assert(i <= length); // Ensures loop does not exceed bounds
        // Ensures all elements in result are unique and from the original array
        assert(std::all_of(result.begin(), result.end(), [&](int x) {
            return std::find(a.begin(), a.begin() + i, x) != a.begin() + i;
        }));
        // Ensures all elements in result are unique
        assert(std::adjacent_find(result.begin(), result.end()) == result.end());

        // Check if current element is not in result
        if (std::find(result.begin(), result.end(), a[i]) == result.end()) {
            result.push_back(a[i]);
        }
    }

    // Postconditions
    // Ensures all elements in result are from the original array
    ENSURE(std::all_of(result.begin(), result.end(), [&](int x) {
        return std::find(a.begin(), a.end(), x) != a.end();
    }));
    // Ensures all elements in result are unique
    ENSURE(std::adjacent_find(result.begin(), result.end()) == result.end());

    return result;
}